#include <bits/stdc++.h>

using pii = std::pair<int, int>;
int dist[17][17];

int getdist(pii &a, pii &b)
{
    return std::abs(a.first - b.first) + std::abs(a.second - b.second);
}

// Traveling Salesman Problem
// Preparing grading in BOJ
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<pii> spots;
    spots.emplace_back(0, 0);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        spots.emplace_back(x, y);
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dist[i][j] = getdist(spots[i], spots[j]);
        }
    }

    std::vector<int> order;
    for (int i = 0; i <= n; i++)
        order.push_back(i);
    int ans = 0x3f3f3f3f;
    while (std::next_permutation(order.begin() + 1, order.end()))
    {
        int tans = 0;
        for (int i = 0; i < n; i++)
        {
            tans += dist[order[i]][order[i + 1]];
        }
        tans += dist[order.back()][0];
        ans = std::min(ans, tans);
    }
    std::cout << ans << '\n';
}