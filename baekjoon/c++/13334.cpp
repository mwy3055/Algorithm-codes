#include <bits/stdc++.h>

using pii = std::pair<int, int>;

int solve(std::vector<pii> &points, int d)
{
    // 우선순위 큐에서는 왼쪽 끝이 작은 순서대로 정렬
    int ans = 0;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

    for (auto &p : points)
    {
        if (p.second - p.first > d)
            continue;

        while (!pq.empty() && p.second - pq.top().first > d)
            pq.pop();
        pq.push(p);
        ans = std::max(ans, (int)pq.size());
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, d;
    std::vector<pii> points;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p1, p2;
        std::cin >> p1 >> p2;
        if (p1 > p2)
            std::swap(p1, p2);
        points.emplace_back(p1, p2);
    }
    std::cin >> d;

    // 오른쪽 끝이 작은 순서대로 정렬
    std::sort(points.begin(), points.end(), [](pii a, pii b) -> bool {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    });
    std::cout << solve(points, d) << '\n';
}