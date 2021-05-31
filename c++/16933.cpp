#include <bits/stdc++.h>
using namespace std;

struct node
{
    int y, x, cnt;
    node(int y, int x, int cnt) : y(y), x(x), cnt(cnt) {}
    bool operator==(const node &n) const
    {
        return this->y == n.y && this->x == n.x;
    }
};

int n, m, k;
char board[1000][1001];
bool visited[1000][1000][11][2]; // [i][j][k][d]: (i, j), k번 벽을 부숨, d: 낮이라면 true

bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}
bool iswall(int y, int x)
{
    return board[y][x] == '1';
}
int solve()
{
    queue<node> q;
    int src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

    node start(0, 0, 0), end(n - 1, m - 1, 0);
    visited[0][0][0][1] = true;
    q.push(start);
    int ans = 1;
    while (!q.empty())
    {
        int siz = q.size();
        while (siz--)
        {
            auto top = q.front();
            auto &y = top.y, &x = top.x, &cnt = top.cnt;
            q.pop();

            if (top == end)
                return ans;
            int nd = !(ans % 2);
            for (int i = 0; i < 4; i++)
            {
                int ny = y + src[i][0], nx = x + src[i][1], nk = cnt;
                if (!isin(ny, nx))
                    continue;
                if (iswall(ny, nx) && ans % 2 && nk < k)
                {
                    nk++;
                    if (!visited[ny][nx][nk][nd])
                    {
                        visited[ny][nx][nk][nd] = true;
                        q.push(node(ny, nx, nk));
                    }
                }
                else if (!iswall(ny, nx) && !visited[ny][nx][nk][nd])
                {
                    visited[ny][nx][nk][nd] = true;
                    q.push(node(ny, nx, nk));
                }
            }
            if (!visited[y][x][cnt][nd])
            {
                visited[y][x][cnt][nd] = true;
                q.push(node(y, x, cnt));
            }
        }
        ans++;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    cout << solve();
}