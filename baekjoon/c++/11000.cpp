#include <bits/stdc++.h>

using lesson = std::pair<int, int>;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<lesson> lessons;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, t;
        std::cin >> s >> t;
        lessons.emplace_back(s, t);
    }
    std::sort(lessons.begin(), lessons.end());

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int ans = 0;
    for (auto &l : lessons)
    {
        while (!pq.empty() && pq.top() <= l.first)
            pq.pop();
        pq.push(l.second);
        ans = std::max(ans, (int)pq.size());
    }
    std::cout << ans;
}