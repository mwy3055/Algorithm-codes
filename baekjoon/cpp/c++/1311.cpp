#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
int n, d[20][20], dp[1 << 21];

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> d[i][j];
        }
    }
}

int solve(int depth, int bitmask)
{
    if (bitmask < 0)
        return INF;
    if (depth == n)
        return (bitmask == 0) ? 0 : INF;

    auto &ret = dp[bitmask];
    if (ret != -1)
        return ret;
    ret = INF;

    for (int work = 0; work < n; work++)
    {
        // 아직 선택되지 않은 일이라면
        if (bitmask & (1 << work))
        {
            ret = std::min(ret, d[depth][work] + solve(depth + 1, bitmask - (1 << work)));
        }
    }
    return ret;
}

int solve()
{
    std::memset(dp, -1, sizeof(dp));
    return solve(0, (1 << n) - 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}