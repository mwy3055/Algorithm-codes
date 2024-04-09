#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using coord = std::pair<int, int>;

int n, m, k, map[10][10];

int atk_type[10][10];
const int ATK_DEFAULT = 0;
const int ATK_ATTACKER = 1;
const int ATK_TARGET = 2;

int last_attack[10][10];

int d[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
coord track[10][10];
const coord NOT_VISIT = coord(-1, -1);

int c[][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

struct weak_cmp
{
    bool operator()(const coord &i, const coord &j)
    {
        auto [ir, ic] = i;
        auto [jr, jc] = j;
        if (map[ir][ic] != map[jr][jc])
            return map[ir][ic] < map[jr][jc];
        else if (last_attack[ir][ic] != last_attack[jr][jc])
            return last_attack[ir][ic] > last_attack[jr][jc];
        else if (ir + ic != jr + jc)
            return ir + ic > jr + jc;
        else
            return ic > jc;
    }
};

struct strong_cmp
{
    bool operator()(const coord &i, const coord &j)
    {
        auto [ir, ic] = i;
        auto [jr, jc] = j;
        if (map[ir][ic] != map[jr][jc])
            return map[ir][ic] > map[jr][jc];
        else if (last_attack[ir][ic] != last_attack[jr][jc])
            return last_attack[ir][ic] < last_attack[jr][jc];
        else if (ir + ic != jr + jc)
            return ir + ic < jr + jc;
        else
            return ic < jc;
    }
};

void init_turn()
{
    std::memset(atk_type, 0, sizeof(atk_type));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            track[i][j] = NOT_VISIT;
        }
    }
}

std::pair<coord, coord> get_attacker_and_target()
{
    std::vector<coord> turrets;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] != 0)
            {
                turrets.emplace_back(i, j);
            }
        }
    }
    std::sort(turrets.begin(), turrets.end(), weak_cmp());
    return std::make_pair(turrets.front(), turrets.back());
}

coord select_attacker()
{
    std::vector<coord> turrets;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] != 0)
            {
                turrets.emplace_back(i, j);
            }
        }
    }
    if (turrets.size() == 1)
        return NOT_VISIT;

    std::sort(turrets.begin(), turrets.end(), weak_cmp());
    return turrets[0];
}

void set_attacker(coord &attacker, int time)
{
    auto [ar, ac] = attacker;
    atk_type[ar][ac] = ATK_ATTACKER;
    last_attack[ar][ac] = time;
}

void increase_attack(coord &attacker)
{
    auto [ar, ac] = attacker;
    map[ar][ac] += n + m;
}

coord select_target(coord &attacker)
{
    std::vector<coord> turrets;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] != 0)
            {
                turrets.emplace_back(i, j);
            }
        }
    }
    std::sort(turrets.begin(), turrets.end(), strong_cmp());
    if (turrets[0] == attacker)
        return turrets[1];
    else
        return turrets[0];
}

void set_attack_target(int r, int c)
{
    atk_type[r][c] = ATK_TARGET;
}

void set_attack_target(coord &target)
{
    auto [tr, tc] = target;
    set_attack_target(tr, tc);
}

bool isin(int r, int c)
{
    return 0 <= r && r < n && 0 <= c && c < m;
}

std::queue<coord> get_laser_path(coord &attacker, coord &target)
{
    // BFS init
    std::queue<coord> q;
    q.push(attacker);
    auto [ar, ac] = attacker;
    track[ar][ac] = attacker;

    bool found = false;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur == target)
        {
            found = true;
            break;
        }

        auto [cr, cc] = cur;
        for (int i = 0; i < 4; i++)
        {
            int nr = (cr + d[i][0] + n) % n, nc = (cc + d[i][1] + m) % m;
            if (isin(nr, nc) && map[nr][nc] > 0 && track[nr][nc] == NOT_VISIT)
            {
                // track!
                track[nr][nc] = cur;
                q.emplace(nr, nc);
            }
        }
    }

    if (!found)
        return std::queue<coord>();

    std::queue<coord> path;
    auto cur = target;
    while (cur != attacker)
    {
        path.push(cur);
        cur = track[cur.first][cur.second];
    }
    return path;
}

void attack(int r, int c, int atk)
{
    map[r][c] = std::max(0, map[r][c] - atk);
}

void laser_attack(coord &attacker, coord &target, std::queue<coord> path)
{
    auto [ar, ac] = attacker;
    int atk = map[ar][ac];
    auto cur = attacker;
    while (true)
    {
        auto [cr, cc] = cur;
        if (cur != attacker && cur != target)
        {
            attack(cr, cc, atk / 2);
            set_attack_target(cur);
        }
        else if (cur == target)
        {
            attack(cr, cc, atk);
            set_attack_target(cur);
        }

        if (path.empty())
            break;
        cur = path.front();
        path.pop();
    }
}

void cannon_attack(coord &attacker, coord &target)
{
    auto [ar, ac] = attacker;
    int atk = map[ar][ac];

    auto [tr, tc] = target;
    attack(tr, tc, atk);
    for (int i = 0; i < 8; i++)
    {
        int nr = (tr + c[i][0] + n) % n, nc = (tc + c[i][1] + m) % m;
        if ((ar != nr || ac != nc) && map[nr][nc] > 0)
        {
            attack(nr, nc, atk / 2);
            set_attack_target(nr, nc);
        }
    }
}

void attack(coord &attacker, coord &target)
{
    // 레이저 가능하면
    auto attack_path = get_laser_path(attacker, target);
    if (!attack_path.empty())
    {
        // 레이저
        laser_attack(attacker, target, attack_path);
    }
    // 불가능하면 포탄
    else
    {
        cannon_attack(attacker, target);
    }
}

void fix_cannon()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] > 0 && atk_type[i][j] == ATK_DEFAULT)
            {
                map[i][j]++;
            }
        }
    }
}

int get_strongest_turret()
{
    int max_turret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            max_turret = std::max(max_turret, map[i][j]);
        }
    }
    return max_turret;
}

int solve()
{
    // K턴동안,
    for (int i = 1; i <= k; i++)
    {
        // init
        init_turn();
        // 공격자 선정
        // auto [attacker, target] = get_attacker_and_target();
        auto attacker = select_attacker();
        if (attacker == NOT_VISIT)
            break;
        set_attacker(attacker, i);
        increase_attack(attacker);
        // 공격 대상 선정
        auto target = select_target(attacker);
        set_attack_target(target);
        // 공격 (레이저 or 포탄)
        attack(attacker, target);
        // 포탑 정비
        fix_cannon();
    }
    // 가장 강한 포탑 반환
    int ans = get_strongest_turret();
    return ans;
}

void getinput()
{
    std::cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> map[i][j];
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}