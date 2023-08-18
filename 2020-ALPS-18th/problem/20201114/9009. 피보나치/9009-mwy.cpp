#include <bits/stdc++.h>

using vi = std::vector<int>;
vi f(45);

void preprocess()
{
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 44; i++)
        f[i] = f[i - 1] + f[i - 2];
}

void solve(vi &ans, int n)
{
    if (n == 0)
        return;

    auto bound = std::lower_bound(f.begin(), f.end(), n) - f.begin();
    if (n == f[bound])
    {
        ans.push_back(n);
        return;
    }
    ans.push_back(f[bound - 1]);
    solve(ans, n - f[bound - 1]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    preprocess();

    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        vi ans;
        std::cin >> n;
        solve(ans, n);
        std::sort(ans.begin(), ans.end());
        for (auto &a : ans)
            std::cout << a << ' ';
        std::cout << '\n';
    }
}