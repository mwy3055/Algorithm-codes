#include <bits/stdc++.h>

using pii = std::pair<int, int>; // cost, node

int n, r;
std::vector<pii> graph[200001];

void getinput()
{
    std::cin >> n >> r;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, d;
        std::cin >> a >> b >> d;
        graph[a].emplace_back(d, b);
        graph[b].emplace_back(d, a);
    }
}

void solve()
{
    std::vector<int> dist(n + 1, 0);
    std::queue<pii> q;
    std::vector<bool> visit(n + 1, false), isleaf(n + 1, false);

    bool is_line = true;
    int giga = -1;
    q.emplace(0, r);
    visit[r] = true;
    while (!q.empty())
    {
        auto [cost, cur] = q.front();
        q.pop();
        dist[cur] = cost;

        if (is_line)
            giga = cur;

        int child = 0;
        for (auto &[len, adj] : graph[cur])
        {
            if (!visit[adj])
            {
                q.emplace(cost + len, adj);
                visit[adj] = true;
                child++;
            }
        }
        if (child > 1 && giga == -1)
        {
            giga = cur;
        }
        else if (child == 0)
        {
            isleaf[cur] = true;
        }
        else if (child > 2)
        {
            is_line = false;
        }
    }
    if (graph[r].size() > 1)
        giga = r;

    int ans1 = dist[giga], ans2 = -1;
    for (int i = 1; i <= n; i++)
    {
        if (isleaf[i])
        {
            ans2 = std::max(ans2, dist[i] - dist[giga]);
        }
    }
    std::cout << ans1 << ' ' << ans2 << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    getinput();
    solve();
}