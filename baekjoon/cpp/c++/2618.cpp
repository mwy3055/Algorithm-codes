#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct coord
{
    int y, x;
};

int dp[1003][1003], track[1003][1003], n, w;
vector<coord> ev;
inline int abs(int a)
{
    return a < 0 ? -a : a;
}
inline int max(int a, int b)
{
    return a < b ? b : a;
}
inline int dist(int i, int j)
{
    return abs(ev[i].x - ev[j].x) + abs(ev[i].y - ev[j].y);
}

int solve(int i, int j) //1번 차가 i번, 2번 차가 j번 사건의 위치에 있을 때, 두 차가 남은 사건을 해결하기 위해 이동해야 하는 거리의 최소 반환
{
    if (dp[i][j] != -1)
        return dp[i][j];

    int now = max(i, j) + 1;
    if (now == w + 2)
        return 0;

    int c1 = solve(now, j) + dist(i, now), c2 = solve(i, now) + dist(j, now);
    if (c1 < c2)
    {
        track[i][j] = 1;
        return dp[i][j] = c1;
    }
    else
    {
        track[i][j] = 2;
        return dp[i][j] = c2;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> n >> w; //n은 필드 크기, w는 사건의 수
    ev = vector<coord>(w + 2);
    ev[0] = {1, 1}, ev[1] = {n, n};
    for (int i = 2; i < w + 2; i++)
        cin >> ev[i].y >> ev[i].x;

    cout << solve(0, 1) << '\n';
    int i = 0, j = 1;
    while (max(i, j) + 1 < w + 2)
    {
        cout << track[i][j] << '\n';
        if (track[i][j] == 1)
            i = max(i, j) + 1;
        else
            j = max(i, j) + 1;
    }
}