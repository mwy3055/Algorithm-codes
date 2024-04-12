#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <algorithm>

using coord = std::pair<int, int>;

int n, m, p, c, d;
int board[50][50]; // id who is on that board, santa or rudolph
const int BOARD_RUDOLPH = 0;
const int BOARD_EMPTY = -1;

int sd[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int rd[][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

struct santa
{
    int no, r, c, score, awake_turn;
    bool retire; // 탈락 여부
    santa(int no, int r, int c) : no(no), r(r), c(c), score(0), awake_turn(0), retire(false) {}
    santa() = default;

    void set_coord(int r, int c)
    {
        this->r = r;
        this->c = c;
    }

    void set_retire()
    {
        retire = true;
        r = c = -1;
    }

    coord get_coord()
    {
        return coord(this->r, this->c);
    }

    void add_score(int score)
    {
        this->score += score;
    }

    // mi: move index
    coord get_move_coord(int mi)
    {
        return coord(this->r + sd[mi][0], this->c + sd[mi][1]);
    }
};

struct rudolph
{
    int r, c;
    rudolph(int r, int c) : r(r), c(c) {}

    void set_coord(int r, int c)
    {
        this->r = r;
        this->c = c;
    }

    // mi: move index
    coord get_move_coord(int mi)
    {
        return coord(this->r + rd[mi][0], this->c + rd[mi][1]);
    }
};

int santa_on_board;
rudolph rudolp(0, 0);
std::vector<santa> santas;

int dist(int r1, int c1, int r2, int c2)
{
    auto dr = r1 - r2;
    auto dc = c1 - c2;
    return dr * dr + dc * dc;
}

int dist(coord c, int r1, int c1)
{
    return dist(c.first, c.second, r1, c1);
}

int dist(coord c1, coord c2)
{
    return dist(c1.first, c1.second, c2.first, c2.second);
}

int dist(rudolph r, santa s)
{
    return dist(r.r, r.c, s.r, s.c);
}

int dist(santa s, rudolph r)
{
    return dist(r, s);
}

void getinput()
{
    std::cin >> n >> m >> p >> c >> d;
    santa_on_board = p;
    santas.resize(p);
    std::memset(board, BOARD_EMPTY, sizeof(board));

    int rr, rc;
    std::cin >> rr >> rc;
    rudolp.r = rr - 1;
    rudolp.c = rc - 1;
    board[rr - 1][rc - 1] = BOARD_RUDOLPH;

    for (int i = 0; i < p; i++)
    {
        int pn, sr, sc;
        std::cin >> pn >> sr >> sc;
        santas[pn - 1] = santa(pn, sr - 1, sc - 1);
        board[sr - 1][sc - 1] = pn;
    }
}

bool isin(int r, int c)
{
    return 0 <= r && r < n &&
           0 <= c && c < n;
}

bool isin(coord c)
{
    return isin(c.first, c.second);
}

// 루돌프에게 밀림 or 연쇄 중
void santa_pushed(santa &s, int dr, int dc, int move)
{
    int nr = s.r + dr * move;
    int nc = s.c + dc * move;
    if (!isin(nr, nc))
    {
        // 탈락
        s.set_retire();
        santa_on_board--;
    }
    // 칸이 비어있는 경우
    else if (board[nr][nc] == BOARD_EMPTY)
    {
        board[nr][nc] = s.no;
        s.set_coord(nr, nc);
    }
    // 다른 산타가 있는 경우
    else
    {
        santa_pushed(santas[board[nr][nc] - 1], dr, dc, 1);

        board[nr][nc] = s.no;
        s.set_coord(nr, nc);
    }
}

struct nearest_santa_cmp
{
    bool operator()(const int &i1, const int &i2)
    {
        auto dist1 = dist(rudolp, santas[i1]);
        auto dist2 = dist(rudolp, santas[i2]);
        if (dist1 != dist2)
            return dist1 < dist2;
        else if (santas[i1].r != santas[i2].r)
            return santas[i1].r > santas[i2].r;
        else
            return santas[i1].c > santas[i2].c;
    }
};

coord get_nearest_santa_coord()
{
    std::vector<int> alive_santa_indices;
    for (int i = 0; i < p; i++)
    {
        if (santas[i].retire)
            continue;
        alive_santa_indices.push_back(i);
    }
    std::sort(alive_santa_indices.begin(), alive_santa_indices.end(), nearest_santa_cmp());
    auto target = alive_santa_indices.front();
    return santas[target].get_coord();
}

int get_rudolph_move_index(coord &co)
{
    int move_index = -1, min_dist = 0x3f3f3f3f;

    auto rr = rudolp.r, rc = rudolp.c;
    for (int i = 0; i < 8; i++)
    {
        int cand_dist = dist(co, rr + rd[i][0], rc + rd[i][1]);
        if (cand_dist < min_dist)
        {
            min_dist = cand_dist;
            move_index = i;
        }
    }
    return move_index;
}

// 이동할 칸에 산타가 있는 경우, 그 산타에게 C점을 주고 C칸 밈
// rmi: rudolph move index
void move_rudolph(int rmi, int turn)
{
    auto [mr, mc] = rudolp.get_move_coord(rmi);
    if (board[mr][mc] != BOARD_EMPTY)
    {
        // 산타가 있음
        auto &target_santa = santas[board[mr][mc] - 1];
        target_santa.add_score(c);
        santa_pushed(target_santa, rd[rmi][0], rd[rmi][1], c);
        target_santa.awake_turn = turn + 2;
    }
    // 루돌프 입주
    board[rudolp.r][rudolp.c] = BOARD_EMPTY;
    rudolp.set_coord(mr, mc);
    board[mr][mc] = BOARD_RUDOLPH;
}

void rudolph_moves(int turn)
{
    // 가장 가까운 산타를 찾기
    auto nearest_santa_coord = get_nearest_santa_coord();
    // 산타에 가장 가까워지는 방향으로 1칸 이동
    auto nmi = get_rudolph_move_index(nearest_santa_coord);
    move_rudolph(nmi, turn);
}

int get_santa_move_index(santa &st)
{
    int move_index = -1, min_dist = dist(st, rudolp);
    for (int i = 0; i < 4; i++)
    {
        auto [mr, mc] = st.get_move_coord(i);
        if (!isin(mr, mc) || board[mr][mc] > 0)
            continue;
        auto move_dist = dist(mr, mc, rudolp.r, rudolp.c);
        if (move_dist < min_dist)
        {
            min_dist = move_dist;
            move_index = i;
        }
    }
    return move_index;
}

// 루돌프와 가장 가까워지는 방향을 찾기
// 비어있는 칸 중 루돌프와 가장 가까워지는 칸 찾기
// 이동
// 루돌프와 충돌했다면, D점을 얻고
// 뒤로 D칸 밀려남
void santa_move(santa &st, int turn)
{
    auto move_index = get_santa_move_index(st);
    if (move_index == -1)
        return;

    board[st.r][st.c] = BOARD_EMPTY;

    auto [sr, sc] = st.get_move_coord(move_index);
    if (board[sr][sc] == BOARD_RUDOLPH)
    {
        st.add_score(d);
        auto push_index = (move_index + 2) % 4;
        santa_pushed(st, sd[push_index][0], sd[push_index][1], d - 1);
        st.awake_turn = turn + 2;
    }
    else if (board[sr][sc] == BOARD_EMPTY)
    {
        st.set_coord(sr, sc);
        board[sr][sc] = st.no;
    }
    else
        exit(-1);
}

void santas_move(int turn)
{
    // 1번부터 각 산타에 대해,
    for (int i = 0; i < p; i++)
    {
        // 그로기 풀기
        if (santas[i].awake_turn == turn)
        {
            santas[i].awake_turn = 0;
        }

        if (santas[i].retire || santas[i].awake_turn)
        {
            continue;
        }
        santa_move(santas[i], turn);
    }
}

void add_bonus_to_alive_santas()
{
    for (int i = 0; i < p; i++)
    {
        if (!santas[i].retire)
        {
            santas[i].add_score(1);
        }
    }
}

void print_result()
{
    for (int i = 0; i < p; i++)
    {
        std::cout << santas[i].score << ' ';
    }
    std::cout << '\n';
}

void solve()
{
    for (int i = 1; i <= m; i++)
    {
        if (santa_on_board == 0)
            break;
        // 루돌프가 움직임
        rudolph_moves(i);
        // 산타가 움직임
        santas_move(i);
        // 탈락하지 않은 산타에게 1점씩 부여
        add_bonus_to_alive_santas();
    }

    print_result();
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}