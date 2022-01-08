#include <bits/stdc++.h>

// 1781번과 동일한 문제
// 마감일, 점수
using hw = std::pair<int, int>;

int n, dmax = 0;
std::vector<hw> homeworks;

int solve()
{
    int ans = 0;

    std::sort(homeworks.begin(), homeworks.end());

    // 점수의 pq
    std::priority_queue<int> pq;
    int idx = n - 1;
    for (int day = dmax; day > 0; day--)
    {
        while (idx >= 0 && homeworks[idx].first == day)
            pq.push(homeworks[idx--].second);
        if (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d, w;
        std::cin >> d >> w;
        homeworks.emplace_back(d, w);
        dmax = std::max(dmax, d);
    }

    std::cout << solve() << '\n';
}