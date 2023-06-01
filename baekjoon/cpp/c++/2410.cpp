#include <bits/stdc++.h>

const int MOD = 1e9;

int n;
int dp[1000001][21], mlog[1000001];

void getinput()
{
    std::cin >> n;
}

void init()
{
    for (int i = 0; i <= 20; i++)
    {
        if ((1 << i) <= 1000000)
        {
            mlog[1 << i] = i;
        }
    }

    for (int i = 1; i <= 1000000; i++)
    {
        if (mlog[i] == 0)
        {
            mlog[i] = mlog[i - 1];
        }
    }
}

int solve(int n, int sq)
{
    if (n == 0)
        return 1;
    auto &ret = dp[n][sq];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = std::min(sq, mlog[n]); i >= 0; i--)
    {
        auto tans = solve(n - (1 << i), i);
        ret = (ret + tans) % MOD;
    }
    return ret;
}

int solve()
{
    std::memset(dp, -1, sizeof(dp));
    init();

    return solve(n, mlog[n]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}