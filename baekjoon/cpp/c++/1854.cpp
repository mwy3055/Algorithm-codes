#include <bits/stdc++.h>

using ll = long long;
using edge = std::pair<ll, ll>; // cost, dest
std::vector<edge> graph[1001];
std::priority_queue<ll> answers[1001]; // k-th shortest path on the top

void solve(int k)
{
    std::priority_queue<edge, std::vector<edge>, std::greater<edge>> pq;

    pq.push(edge(0, 1));
    while (!pq.empty())
    {
        auto &top = pq.top();
        auto cost = top.first, cur = top.second;
        pq.pop();

        for (auto &e : graph[cur])
        {
            auto adjcost = e.first, adj = e.second;
            auto &a = answers[adj];
            if (a.size() < k || a.top() > cost + adjcost)
            {
                if (a.size() == k)
                    a.pop();
                a.push(cost + adjcost);
                pq.push(edge(cost + adjcost, adj));
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
    }

    answers[1].push(0);
    solve(k);

    for (int i = 1; i <= n; i++)
    {
        if (answers[i].size() < k)
            std::cout << -1 << '\n';
        else
            std::cout << answers[i].top() << '\n';
    }
}