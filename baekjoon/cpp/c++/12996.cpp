#include <bits/stdc++.h>

using ll = long long;
const ll MOD = 1e9 + 7;

int s, a, b, c, mval;
ll dp[51];
ll combi[51][51];

void getinput()
{
    std::cin >> s >> a >> b >> c;
}

void init()
{
    // combination
    combi[0][0] = 1;
    for (int i = 1; i <= 50; i++)
    {
        combi[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            combi[i][j] = (combi[i - 1][j - 1] + combi[i - 1][j]) % MOD;
        }
    }
}

ll comb(int i, int j)
{
    return combi[i][j] % MOD;
}

ll solve(int song)
{
    if (song <= 0)
        return 0;
    auto &ret = dp[song];
    if (ret != -1)
        return ret;

    ret = comb(song, a);
    ret = (ret * comb(song, b)) % MOD;
    ret = (ret * comb(song, c)) % MOD;

    for (int i = song - 1; i >= a; i--)
        ret = (ret - (comb(song, i) * solve(i)) % MOD + MOD) % MOD;

    return ret;
}

ll solve()
{
    std::memset(dp, -1, sizeof(dp));
    init();
    if (a + b + c < s)
        return 0;
    return solve(s);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}