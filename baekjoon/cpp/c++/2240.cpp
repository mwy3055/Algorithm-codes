#include <bits/stdc++.h>
using namespace std;

int t, w, order[1000], dp[1000][2][31];

int solve(int ctime, int cloc, int left)
{
    int &ret = dp[ctime][cloc][left];
    if (ctime >= t)
    {
        return 0;
    }
    if (ret != -1)
        return ret;

    int ans = solve(ctime + 1, cloc, left);
    if (left)
        ans = max(ans, solve(ctime, cloc ^ 1, left - 1));
    return ret = ans + (cloc == order[ctime]);
}

void init()
{
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 31; k++)
                dp[i][j][k] = -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    cin >> t >> w;
    for (int i = 0; i < t; i++)
    {
        cin >> order[i];
        order[i]--;
    }

    cout << solve(0, 0, w);
}