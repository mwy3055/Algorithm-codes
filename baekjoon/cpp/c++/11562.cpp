#include <bits/stdc++.h>

using pii = std::pair<int, int>; // cost, node
using vpii = std::vector<pii>;

const int INF = 1e9;
int n, m;
std::vector<vpii> graph(250, vpii());

int d[250][250];

void getinput()
{
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, b;
        std::cin >> u >> v >> b;
        u--, v--;
        if (b == 0)
        {
            graph[u].emplace_back(v, 0);
            graph[v].emplace_back(u, 1);
        }
        else
        {
            graph[u].emplace_back(v, 0);
            graph[v].emplace_back(u, 0);
        }
    }
}

void preprocess(int s)
{
    // bfs with pq
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    std::vector<int> dist(n, INF);

    pq.emplace(0, s);
    dist[s] = 0;
    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();

        for (auto &[adj, type] : graph[node])
        {
            int ncost = cost + type;
            if (ncost < dist[adj])
            {
                dist[adj] = ncost;
                pq.emplace(ncost, adj);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        d[s][i] = dist[i];
    }
}

void solve()
{
    for (int i = 0; i < n; i++)
        preprocess(i);

    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        int s, e;
        std::cin >> s >> e;
        std::cout << d[s - 1][e - 1] << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}