#include <bits/stdc++.h>

using pii = std::pair<int, int>;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<pii> times;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        std::cin >> s >> e;
        times.emplace_back(s, e);
    }
    std::sort(times.begin(), times.end(), [](const pii &a, const pii &b) {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    });

    auto comp = [](const pii &a, const pii &b) {
        return a.second > b.second;
    };
    std::priority_queue<pii, std::vector<pii>, decltype(comp)> pq(comp);
    int ans = 0, em = 0, xm = (1LL << 31) - 1;
    for (auto &time : times)
    {
        int lasttime = -1;
        while (!pq.empty() && pq.top().second <= time.first)
        {
            lasttime = pq.top().second;
            pq.pop();
        }
        pq.push(time);
        if (ans < pq.size())
        {
            ans = pq.size();
            em = time.first;
            xm = std::min(pq.top().second, time.second);
        }
        else if (ans == pq.size())
        {
            if (lasttime == time.first)
                xm = time.second;
        }
    }
    std::cout << ans << '\n'
              << em << ' ' << xm;
}