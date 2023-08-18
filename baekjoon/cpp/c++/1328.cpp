#include <bits/stdc++.h>

using ll = long long;

const ll MOD = 1000000007;
ll dp[101][101][101];

// n: highest height of bulding
// l, r: same as problem description
// increase height of all buildings in case of (n - 1) by 1, then add building whose height is 1
// add leftmost(1), rightmost(1), between somewhere(n - 2)
ll solve(int n, int l, int r)
{
    auto &ret = dp[n][l][r];
    if (ret != -1)
        return ret;
    if (n == 0)
        return ret = 0;
    if ((l == 1 && r == n) || (l == n && r == 1))
        return ret = 1;
    if (l == 0 || r == 0)
        return ret = 0;
    ret = 0;
    ret = (ret + solve(n - 1, l, r) * (n - 2)) % MOD;
    ret = (ret + solve(n - 1, l - 1, r)) % MOD;
    ret = (ret + solve(n - 1, l, r - 1)) % MOD;
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(dp, -1, sizeof(dp));

    int n, l, r;
    std::cin >> n >> l >> r;
    std::cout << solve(n, l, r);
}