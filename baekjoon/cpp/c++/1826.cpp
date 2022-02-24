#include <bits/stdc++.h>

using pii = std::pair<int, int>; // position, amount of fuel

int solve(int &n, int &l, int &p, std::vector<pii> &fuels)
{
    std::sort(fuels.begin(), fuels.end());
    int ans = 0;
    int forward_dist = p; // 더 갈 수 있는 거리

    std::priority_queue<int> pq;

    int i = 0;
    while (forward_dist < l)
    {
        // 갈 수 있는 거리에 있는 모든 주유소 중
        while (i < fuels.size() && fuels[i].first <= forward_dist)
        {
            pq.push(fuels[i].second);
            i++;
        }
        if (pq.empty())
            break;
        // 가장 기름이 많은 주유소에 들른다.
        forward_dist += pq.top();
        // 전부 pop하지 않는 이유: 지금 고르지 않더라도 나중에 필요할 수도 있어서
        pq.pop();
        ans++;
    }
    return forward_dist >= l ? ans : -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, l, p;
    std::vector<pii> fuels;

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        fuels.emplace_back(a, b);
    }
    std::cin >> l >> p;
    std::cout << solve(n, l, p, fuels) << '\n';
}