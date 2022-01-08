#include <bits/stdc++.h>

using pii = std::pair<int, int>;
using vi = std::vector<int>;

/**
 * 도시락을 데우는 순서와 관계없이 데우는 시간의 합은 항상 같다.
 * 따라서 먹는 시간을 최대한 겹치게 해야 한다.
 * 즉 먹는 데 오래 걸리는 도시락을 먼저 데워야 한다.
 */
int solve(int &n, vi &m, vi &e)
{
    std::vector<pii> boxes;
    for (int i = 0; i < n; i++)
    {
        boxes.emplace_back(-e[i], m[i]);
    }
    std::sort(boxes.begin(), boxes.end());

    int ans = 0, htime = 0; // htime: 이 도시락을 데우기 시작하는 시간
    for (auto &box : boxes)
    {
        auto &eat = box.first, &heat = box.second;
        eat *= -1;
        ans = std::max(ans, htime + heat + eat);
        htime += heat;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        std::cin >> n;
        vi m(n), e(n);
        for (auto &mi : m)
            std::cin >> mi;
        for (auto &ei : e)
            std::cin >> ei;
        std::cout << solve(n, m, e) << '\n';
    }
}