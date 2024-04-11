#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using coord = std::pair<int, int>; // r, c
using ll = long long;

struct rabbit
{
    // 기본 정보
    int pid, d, move_count;
    // 위치
    int r, c;

    rabbit(int pid, int d) : pid(pid), d(d), move_count(0), r(0), c(0) {}

    void select_rabbit()
    {
        this->move_count += 1;
    }

    void multiple_d(int l)
    {
        d *= l;
    }

    void set_position(int r, int c)
    {
        this->r = r;
        this->c = c;
    }
};

struct run_cmp
{
    bool operator()(const rabbit &r1, const rabbit &r2)
    {
        return !prior_rabbit(r1, r2);
    }

    bool prior_rabbit(const rabbit &r1, const rabbit &r2)
    {
        if (r1.move_count != r2.move_count)
            return r1.move_count < r2.move_count;
        else if (r1.r + r1.c != r2.r + r2.c)
            return r1.r + r1.c < r2.r + r2.c;
        else if (r1.r != r2.r)
            return r1.r < r2.r;
        else if (r1.c != r2.c)
            return r1.c < r2.c;
        else
            return r1.pid < r2.pid;
    }
};

struct bonus_score_cmp
{
    bool operator()(const rabbit &r1, const rabbit &r2)
    {
        if (r1.r + r1.c != r2.r + r2.c)
            return r1.r + r1.c > r2.r + r2.c;
        else if (r1.r != r2.r)
            return r1.r > r2.r;
        else
            return r1.c > r2.c;
    }
};

struct coord_cmp
{
    bool operator()(const coord &p, const coord &q)
    {
        if (p.first + p.second != q.first + q.second)
            return p.first + p.second > q.first + q.second;
        else if (p.first != q.first)
            return p.first > q.first;
        else
            return p.second > q.second;
    }
};

int n, m, p;
std::vector<rabbit> rabbits; // pid, rabbit
std::unordered_map<int, ll> rabbits_score;
ll total_score;

void getinput()
{
    std::cin >> n >> m >> p;
    for (int i = 0; i < p; i++)
    {
        int pid, dist;
        std::cin >> pid >> dist;
        rabbits.emplace_back(pid, dist);
        rabbits_score[pid] = 0;
    }
}

int d[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool isin(int r, int c)
{
    return 0 <= r && r < n &&
           0 <= c && c < m;
}

coord get_move_coord(int r, int c, int dr, int dc, int move)
{
    r += dr * (move % (2 * (n - 1)));
    c += dc * (move % (2 * (m - 1)));

    while (!isin(r, c))
    {
        if (r < 0)
            r = -r;
        else if (r >= n)
            r -= (r - (n - 1)) * 2;
        if (c < 0)
            c = -c;
        else if (c >= m)
            c -= (c - (m - 1)) * 2;
    }

    return coord(r, c);
}

coord get_move_coords(rabbit &rab)
{
    std::vector<coord> candidates;
    for (int i = 0; i < 4; i++)
    {
        auto candidate = get_move_coord(rab.r, rab.c, d[i][0], d[i][1], rab.d);
        candidates.push_back(candidate);
    }
    std::sort(candidates.begin(), candidates.end(), coord_cmp());
    return candidates.front();
}

void take_runs(int k, int s)
{
    // run init
    std::priority_queue<rabbit, std::vector<rabbit>, run_cmp> pq;
    for (auto &r : rabbits)
    {
        pq.push(r);
    }
    std::set<int> run_rabbits_pid; // exclude pid, score

    for (int i = 0; i < k; i++)
    {
        auto run_rabbit = pq.top();
        pq.pop();
        run_rabbit.select_rabbit();

        auto [nr, nc] = get_move_coords(run_rabbit);
        run_rabbit.set_position(nr, nc);

        for (auto &rab : rabbits_score)
        {
            if (rab.first == run_rabbit.pid)
            {
                rab.second += (nr + nc + 2);
                total_score += (nr + nc + 2);
                break;
            }
        }

        pq.push(run_rabbit);
        run_rabbits_pid.insert(run_rabbit.pid);
    }

    rabbits.clear();
    while (!pq.empty())
    {
        rabbits.push_back(pq.top());
        pq.pop();
    }

    // 우선순위가 가장 높은 토끼를 골라, s점 더하기
    std::vector<rabbit> run_rabbits;
    for (int i = 0; i < p; i++)
    {
        if (run_rabbits_pid.find(rabbits[i].pid) != run_rabbits_pid.end())
        {
            run_rabbits.push_back(rabbits[i]);
        }
    }
    std::sort(run_rabbits.begin(), run_rabbits.end(), bonus_score_cmp());
    for (int i = 0; i < p; i++)
    {
        if (rabbits[i].pid != run_rabbits[0].pid)
        {
            rabbits_score[rabbits[i].pid] += s;
        }
    }
    total_score += s;
}

void extend_distance(int pid, int l)
{
    for (int i = 0; i < p; i++)
    {
        if (rabbits[i].pid == pid)
        {
            rabbits[i].multiple_d(l);
            break;
        }
    }
}

ll find_best_score()
{
    ll max_score = -1;
    for (auto &[pid, score] : rabbits_score)
    {
        if (total_score - score > max_score)
        {
            max_score = total_score - score;
        }
    }
    return max_score;
}

void execute_query()
{
    int type;
    std::cin >> type;
    if (type == 100)
    {
        getinput();
    }
    else if (type == 200)
    {
        int k, s;
        std::cin >> k >> s;
        take_runs(k, s);
    }
    else if (type == 300)
    {
        int pid, l;
        std::cin >> pid >> l;
        extend_distance(pid, l);
    }
    else if (type == 400)
    {
        auto best_score = find_best_score();
        std::cout << best_score << '\n';
    }
    else
        exit(-1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        execute_query();
    }
    // n = 3, m = 5;
    // while (true)
    // {
    //     int r, c, dr, dc, move;
    //     std::cin >> r >> c >> dr >> dc >> move;
    //     auto co = get_move_coord(r, c, dr, dc, move);
    //     std::cout << co.first << ' ' << co.second << '\n';
    //     std::cout.flush();
    // }
}