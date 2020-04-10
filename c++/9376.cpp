// not an answer code
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Coord;
typedef pair<int, Coord> node; // number of door opened, coord
const int INF = 1e9;

int h, w, src[][2] = {0, 1, 1, 0, 0, -1, -1, 0}, from[100][100][2];
char board[100][101];
bool doorused[100][100];
vector<Coord> prisoner;

bool isin(int y, int x)
{
    return 0 <= y && y < h && 0 <= x && x < w;
}
void init() /* init global variables */
{
    prisoner.clear();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (board[i][j] == '$')
                prisoner.push_back(Coord(i, j));
            memset(from[i][j], -1, sizeof(int) * 2);
            //doorused[i][j] = false;
        }
    }
}

// 실제로 이동한 경로에 있는 문만 count해야
// (a의 정답)+(b의 정답)이 정답이 아닐지도?
int bfs(Coord &s, int nth)
{
    priority_queue<node, vector<node>, greater<node>> pq;
    bool visit[100][100] = {false};

    int rtn = INF;
    pq.push(node(0, s));
    visit[s.first][s.second] = true;
    while (!pq.empty())
    {
        auto top = pq.top();
        auto &d = top.first, &y = top.second.first, &x = top.second.second;
        pq.pop();

        for (int i = 0; i < 4; i++)
        {
            int nd = d, ny = y + src[i][0], nx = x + src[i][1];
            if (!isin(ny, nx))
            {
                rtn = min(rtn, nd);
                continue;
            }
            if (visit[ny][nx] || board[ny][nx] == '*')
                continue;

            if (board[ny][nx] == '#')
                nd++;
            pq.push(node(nd, Coord(ny, nx)));
            visit[ny][nx] = true;
            from[ny][nx][nth] = i;
        }
    }
    return rtn;
}
void doorinit()
{
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            doorused[i][j] = false;
}
int follow(int &y, int &x, int i)
{
    if (board[y][x] != '$' && from[y][x][i] == -1)
        return INF;
    int cy = y, cx = x, rtn = 0;
    while (cy != prisoner[i].first || cx != prisoner[i].second)
    {
        if (board[cy][cx] == '#' && !doorused[cy][cx])
        {
            doorused[cy][cx] = true;
            rtn++;
        }
        int dy = src[from[cy][cx][i]][0], dx = src[from[cy][cx][i]][1];
        cy -= dy, cx -= dx;
    }
    return rtn;
}
int track(int y, int x)
{
    if (board[y][x] == '*')
        return INF;

    doorinit();
    int ans = follow(y, x, 0);
    ans += follow(y, x, 1);
    return ans;
}
int solve()
{
    int idx = 0, ans = 0;
    for (auto &p : prisoner)
        ans += bfs(p, idx++);

    for (int j = 0; j < w; j++)
    {
        ans = min(ans, track(0, j));
        ans = min(ans, track(h - 1, j));
    }
    for (int i = 1; i < h - 1; i++)
    {
        ans = min(ans, track(i, 0));
        ans = min(ans, track(i, w - 1));
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> h >> w;
        for (int i = 0; i < h; i++)
            cin >> board[i];

        init();
        cout << solve() << '\n';
    }
}