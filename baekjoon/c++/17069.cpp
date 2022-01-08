#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = ((ll)1) << 61 - 1;
ll home[33][33], dp[33][33][3], n; // (y, x) with direction dir.. 0: horizontal, 1: diagnoal, 2: vertical
vector<int> r[3];

bool isin(int y, int x)
{
    return 0 < y && y <= n && 0 < x && x <= n;
}
bool cango(int ey, int ex, int ny, int nx, int dir)
{
    if (!isin(ny, nx))
        return false;
    if (dir == 1)
    {
        return home[ey][ex + 1] == 0 && home[ey + 1][ex] == 0 && home[ny][nx] == 0;
    }
    else
    {
        return home[ny][nx] == 0;
    }
}
ll solve(int sy, int sx, int ey, int ex, int dir)
{
    ll &ret = dp[sy][sx][dir];
    if (ey == n && ex == n)
        return ret = 1;
    if (ret != INF)
        return ret;

    static int d[][2] = {0, 1, 1, 1, 1, 0};

    ll ans = 0;
    for (auto &i : r[dir])
    {
        int ny = ey + d[i][0], nx = ex + d[i][1];
        if (cango(ey, ex, ny, nx, i))
            ans += solve(ey, ex, ny, nx, i);
    }
    return ret = ans;
}

void init()
{
    for (int i = 0; i <= 32; i++)
        for (int j = 0; j <= 32; j++)
            for (int k = 0; k < 3; k++)
                dp[i][j][k] = INF;

    r[0].push_back(0);
    r[0].push_back(1);
    r[1].push_back(0);
    r[1].push_back(1);
    r[1].push_back(2);
    r[2].push_back(1);
    r[2].push_back(2);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> home[i][j];

    cout << solve(1, 1, 1, 2, 0);
}