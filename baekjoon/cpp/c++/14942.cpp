#include <bits/stdc++.h>

using pii = std::pair<int, int>; // dest, cost

const int MAX = 100000;
int n, energy[MAX + 1], dist[MAX + 1], parent[MAX + 1];
std::vector<pii> graph[MAX + 1];
std::vector<bool> visit(MAX + 1, false);

void getinput()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> energy[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
}

void dfs(int cur, int d)
{
    visit[cur] = true;
    dist[cur] = d;
    for (auto &[dest, cost] : graph[cur])
    {
        if (!visit[dest])
        {
            parent[dest] = cur;
            dfs(dest, d + cost);
        }
    }
}

int solve(int ant)
{
    // O(N^2)로 풀리면 안 되는데..
    auto cur = ant, e = energy[ant];
    while (cur != 1)
    {
        if (e < dist[cur] - dist[parent[cur]])
            break;
        e -= dist[cur] - dist[parent[cur]];
        cur = parent[cur];
    }
    return cur;
}

void solve()
{
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        std::cout << solve(i) << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}