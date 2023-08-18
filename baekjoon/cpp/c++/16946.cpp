#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, m, src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char Map[1000][1001], dp[1000][1000];
bool visit[1000][1000];
int group[1000][1000], gcount = 1;

void getinput()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> Map[i];
}

bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}
bool iswall(int y, int x)
{
    return Map[y][x] == '1';
}
int solve(int &y, int &x)
{
    if (!iswall(y, x))
        return 0;
    char &ret = dp[y][x];
    if (ret)
        return ret;

    set<int> s;
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + src[i][0], nx = x + src[i][1];
        if (isin(ny, nx) && !iswall(ny, nx) && s.find(group[ny][nx]) == s.end())
        {
            ans += dp[ny][nx];
            s.insert(group[ny][nx]);
        }
    }
    return ret = (ans + 1) % 10;
}
void bfs(int y, int x)
{
    int ans = 0;
    queue<pii> q;
    vector<pii> connected;

    visit[y][x] = true;
    q.push({y, x});
    connected.push_back({y, x});
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        ans++;

        for (int i = 0; i < 4; i++)
        {
            int ny = top.first + src[i][0], nx = top.second + src[i][1];
            if (isin(ny, nx) && !iswall(ny, nx) && !visit[ny][nx])
            {
                visit[ny][nx] = true;
                q.push({ny, nx});
                connected.push_back({ny, nx});
            }
        }
    }

    for (auto &c : connected)
    {
        dp[c.first][c.second] = ans % 10;
        group[c.first][c.second] = gcount;
    }
    gcount++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    getinput();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!iswall(i, j) && !visit[i][j])
                bfs(i, j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << solve(i, j);
        cout << '\n';
    }
}