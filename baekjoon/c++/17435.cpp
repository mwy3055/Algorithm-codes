#include <bits/stdc++.h>

int f[200001], dp[21][200001];

int log2(int n) // log2의 가우스
{
    int cnt = 0;
    while (n > 1)
    {
        cnt++;
        n >>= 1;
    }
    return cnt;
}
void preprocess(const int &m)
{
    for (int i = 1; i <= m; i++)
        dp[0][i] = f[i];

    for (int dep = 1; dep < 20; dep++)
    {
        for (int i = 1; i <= m; i++)
        {
            dp[dep][i] = dp[dep - 1][dp[dep - 1][i]];
        }
    }
}
int query(int n, int x)
{
    int log = log2(n);
    if (n == (1 << log))
    {
        return dp[log][x];
    }
    return query(n - (1 << log), dp[log][x]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int m;
    std::cin >> m;
    for (int i = 1; i <= m; i++)
        std::cin >> f[i];

    preprocess(m);

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        int n, x;
        std::cin >> n >> x;
        std::cout << query(n, x) << '\n';
    }
}