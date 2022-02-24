#include <bits/stdc++.h>

using vi = std::vector<int>;
vi tri(1001), tetra(1001), dp(300001); // 사면체

int solve(int bomb)
{
    if (bomb == 0)
        return 0;
    if (dp[bomb])
        return dp[bomb];

    int &ret = dp[bomb];
    ret = 0x3f3f3f3f;
    int rmax = std::lower_bound(tetra.begin(), tetra.end(), bomb) - tetra.begin();
    for (int i = rmax; i > 0; i--)
    {
        if (bomb - tetra[i] >= 0)
            ret = std::min(ret, solve(bomb - tetra[i]) + 1);
    }
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    tri[1] = tetra[1] = 1;
    for (int i = 2; i <= 1000; i++)
    {
        tri[i] = tri[i - 1] + i;
        tetra[i] = tetra[i - 1] + tri[i];
    }

    int n;
    std::cin >> n;
    std::cout << solve(n) << '\n';
}