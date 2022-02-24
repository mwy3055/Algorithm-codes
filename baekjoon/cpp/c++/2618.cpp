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

int solve(int i, int j) //1�� ���� i��, 2�� ���� j�� ����� ��ġ�� ���� ��, �� ���� ���� ����� �ذ��ϱ� ���� �̵��ؾ� �ϴ� �Ÿ��� �ּ� ��ȯ
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

    cin >> n >> w; //n�� �ʵ� ũ��, w�� ����� ��
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