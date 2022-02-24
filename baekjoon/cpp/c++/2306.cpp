#include <bits/stdc++.h>

std::string s;
int dp[501][501]; // dp[l][r]: [l, r) 구간에서 가장 긴 KOI 유전자의 길이

int solve(int l, int r)
{
    auto &ret = dp[l][r];
    if (l > r) // 길이가 1 이하인 문자열은 KOI가 아님
        return ret = 0;
    if (ret != -1)
        return ret;

    ret = 0;
    // aXt or gYc
    if ((s[l] == 'a' && s[r - 1] == 't') || (s[l] == 'g' && s[r - 1] == 'c'))
        ret = std::max(ret, solve(l + 1, r - 1) + 2);

    // XY
    for (int k = l + 1; k < r; k++)
        ret = std::max(ret, solve(l, k) + solve(k, r));
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(dp, -1, sizeof(dp));

    std::cin >> s;
    std::cout << solve(0, s.length());
}