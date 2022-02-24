#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> coord;
const int INF = 0x6f6f6f6f;
int w, h, idx[20][20], d[11][11]; // idx: 전부 0으로 초기화, d: INF로 초기화
char board[20][21];
deque<coord> points;

bool isin(int y, int x)
{
    return 0 <= y && y < h && 0 <= x && x < w;
}
void bfs(int &nth, coord &s)
{
    static int src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    queue<coord> q;
    bool visit[20][20] = {false};
    memset(d + nth, 0x6f, sizeof(int) * points.size());

    visit[s.first][s.second] = true;
    q.push(s);
    int cnt = 0;
    while (!q.empty())
    {
        int siz = q.size();
        while (siz--)
        {
            auto top = q.front();
            auto &y = top.first, &x = top.second;
            q.pop();

            if (board[y][x] == 'o' || board[y][x] == '*')
                d[nth][idx[y][x]] = cnt;
            for (int i = 0; i < 4; i++)
            {
                int ny = y + src[i][0], nx = x + src[i][1];
                if (isin(ny, nx) && !visit[ny][nx] && board[ny][nx] != 'x')
                {
                    visit[ny][nx] = true;
                    q.push(coord(ny, nx));
                }
            }
        }
        cnt++;
    }
}
int getans(vector<int> &arr)
{
    int rtn = 0;
    for (int i = 0; i < arr.size() - 1; i++)
        rtn += d[arr[i]][arr[i + 1]];
    return rtn;
}
int solve()
{
    for (int i = 0; i < points.size(); i++)
        idx[points[i].first][points[i].second] = i;
    for (int i = 0; i < points.size(); i++)
    {
        bfs(i, points[i]);
        for (int j = 0; j < points.size(); j++)
        {
            if (d[i][j] == INF)
                return -1;
        }
    }

    vector<int> arr;
    for (int i = 0; i < points.size(); i++)
        arr.push_back(i);

    int ans = INF;
    do
    {
        ans = min(ans, getans(arr));
    } while (next_permutation(arr.begin() + 1, arr.end()));
    return ans;
}

void init()
{
    points.clear();
    for (int i = 0; i < h; i++)
        memset(idx + i, 0, sizeof(int) * w);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true)
    {
        cin >> w >> h;
        if (h == 0 && w == 0)
            break;
        init();
        for (int i = 0; i < h; i++)
        {
            cin >> board[i];
            for (int j = 0; j < w; j++)
            {
                if (board[i][j] == 'o')
                    points.push_front(coord(i, j));
                else if (board[i][j] == '*')
                    points.push_back(coord(i, j));
            }
        }
        cout << solve() << '\n';
    }
}