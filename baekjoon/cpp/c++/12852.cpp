#include <bits/stdc++.h>
using namespace std;

int dp[1000001], track[1000001];
void solve(int &n)
{
    dp[1] = 0;
    dp[2] = 1, track[2] = 2;
    dp[3] = 1, track[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        int mval = 0x3f3f3f3f, type = -1;
        if (i % 3 == 0 && dp[i / 3] + 1 < mval)
        {
            mval = dp[i / 3] + 1;
            type = 1;
        }
        if (i % 2 == 0 && dp[i / 2] + 1 < mval)
        {
            mval = dp[i / 2] + 1;
            type = 2;
        }
        if (dp[i - 1] + 1 < mval)
        {
            mval = dp[i - 1] + 1;
            type = 3;
        }
        dp[i] = mval;
        track[i] = type;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    solve(n);

    cout << dp[n] << '\n';
    int cur = n;
    do
    {
        cout << cur << ' ';
        switch (track[cur])
        {
        case 1:
            cur /= 3;
            break;
        case 2:
            cur /= 2;
            break;
        default:
            cur--;
        }
    } while (cur);
}