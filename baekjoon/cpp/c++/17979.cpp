#include <bits/stdc++.h>

struct appear
{
    int s, e, t;
    appear(int s, int e, int t) : s(s), e(e), t(t) {}
    bool operator<(appear a)
    {
        if (this->s != a.s)
            return this->s < a.s;
        else if (this->e != a.e)
            return this->e < a.e;
        return this->t < a.t;
    }
    int getamount()
    {
        return e - s;
    }
};

int m, n, price[101], dp[15010];
std::vector<appear> appears;

int solve(int time, int index)
{
    if (time >= 15000)
        return 0;
    auto &ret = dp[time];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = index; i < n; i++)
    {
        auto &a = appears[i];
        if (a.s >= time)
        {
            ret = std::max(ret, solve(a.e, i + 1) + a.getamount() * price[a.t]);
        }
    }
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(dp, -1, sizeof(dp));

    std::cin >> m >> n;
    for (int i = 1; i <= m; i++)
        std::cin >> price[i];
    for (int i = 0; i < n; i++)
    {
        int s, e, t;
        std::cin >> s >> e >> t;
        appears.emplace_back(s, e, t);
    }
    std::sort(appears.begin(), appears.end());
    std::cout << solve(0, 0);
}