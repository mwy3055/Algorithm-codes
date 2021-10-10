#include <bits/stdc++.h>

using vi = std::vector<int>;

int solve(int &n, vi &russia, vi &korea)
{
    std::multiset<int> s(korea.begin(), korea.end());

    int ans = 0;
    for (auto &r : russia)
    {
        auto it = s.lower_bound(r);
        if (it != s.end())
        {
            s.erase(it);
            ans++;
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int c;
    std::cin >> c;
    for (int i = 0; i < c; i++)
    {
        int n;
        std::cin >> n;
        vi russia(n), korea(n);
        for (auto &r : russia)
            std::cin >> r;
        for (auto &k : korea)
            std::cin >> k;
        std::cout << solve(n, russia, korea) << '\n';
    }
}