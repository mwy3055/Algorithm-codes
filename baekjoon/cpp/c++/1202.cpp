#include <bits/stdc++.h>

struct gem
{
    int m, v;
    gem(int m, int v) : m(m), v(v) {}
};

struct cmp
{
    bool operator()(gem a, gem b)
    {
        if (a.v != b.v)
            return a.v > b.v;
        return a.m < b.m;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;
    std::vector<gem> gems;
    for (int i = 0; i < n; i++)
    {
        int m, v;
        std::cin >> m >> v;
        gems.emplace_back(m, v);
    }
    std::multiset<int> bags;
    for (int i = 0; i < k; i++)
    {
        int c;
        std::cin >> c;
        bags.insert(c);
    }

    std::sort(gems.begin(), gems.end(), cmp());

    long long ans = 0;
    for (auto &g : gems)
    {
        if (bags.empty())
            break;
        auto it = bags.lower_bound(g.m);
        if (it == bags.end())
            continue;
        ans += g.v;
        bags.erase(it);
    }
    std::cout << ans << '\n';
}