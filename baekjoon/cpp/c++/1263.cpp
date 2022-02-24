#include <bits/stdc++.h>

struct work
{
    int t, s;
    work(int t, int s) : t(t), s(s) {}
    bool operator<(const work &w)
    {
        if (this->s != w.s)
            return this->s < w.s;
        return this->t < w.t;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<work> works;
    for (int i = 0; i < n; i++)
    {
        int t, s;
        std::cin >> t >> s;
        works.emplace_back(t, s);
    }

    std::sort(works.begin(), works.end());
    int cur = works.back().s;
    for (auto it = works.rbegin(); it != works.rend(); it++)
    {
        auto w = *it;
        cur = std::min(cur, w.s) - w.t;
    }
    if (cur >= 0)
        std::cout << cur;
    else
        std::cout << -1;
}