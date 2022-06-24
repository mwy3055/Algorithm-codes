#include <bits/stdc++.h>

using vi = std::vector<int>;
using pii = std::pair<int, int>;
using edge = pii; // cost, dest
const int INF = 0x3f3f3f3f;

int n, m, j, k;
std::vector<edge> edges[5001];
int type[5001];
int dist[5001];

void getinput()
{
    std::cin >> n >> m >> j >> k;
    for (int i = 0; i < k; i++)
    {
        int house;
        std::cin >> house;
        type[house] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        int house;
        std::cin >> house;
        type[house] = 2;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        edges[x].emplace_back(z, y);
        edges[y].emplace_back(z, x);
    }
}

void init()
{
    std::memset(dist, 0x3f, sizeof(dist));
}

void dijkstra()
{
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    dist[j] = 0;
    pq.push({0, j});
    while (!pq.empty())
    {
        auto cur = pq.top().second;
        pq.pop();
        for (auto [cost, dest] : edges[cur])
        {
            int &old = dist[dest];
            int new_dist = dist[cur] + cost;
            if (old > new_dist)
            {
                old = new_dist;
                pq.push({new_dist, dest});
            }
        }
    }
}

void solve()
{
    init();
    dijkstra();

    std::vector<pii> d;
    for (int i = 1; i <= n; i++)
    {
        if (type[i] != 0 && dist[i] != INF)
        {
            d.emplace_back(dist[i], i);
        }
    }
    if (d.empty())
    {
        std::cout << -1 << '\n';
        return;
    }
    std::sort(d.begin(), d.end());

    // [0, i)
    int min_dist = d[0].first;
    int min_type = 3;
    for (int i = 0; i < d.size() && d[i].first == min_dist; i++)
    {
        min_type = std::min(min_type, type[d[i].second]);
    }

    if (min_type == 1)
    {
        std::cout << "A" << '\n'
                  << min_dist << '\n';
    }
    else if (min_type == 2)
    {
        std::cout << "B" << '\n'
                  << min_dist << '\n';
    }
    else
    {
        std::cout << -1 << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}