#include <bits/stdc++.h>

// cost, dest
using edge = std::pair<int, int>;
// dist, current vertex
using elem = std::pair<int, int>;
const int INF = 0x7fffffff;

int v, e, p;
std::vector<edge> graph[5001];

void getinput()
{
    std::cin >> v >> e >> p;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
        graph[b].emplace_back(c, a);
    }
}

int dijkstra(int s, int e)
{
    std::vector<int> d(v + 1, INF);
    d[s] = 0;

    std::priority_queue<elem, std::vector<elem>, std::greater<elem>> pq;
    pq.emplace(0, s);
    while (!pq.empty())
    {
        auto [cur_cost, cur] = pq.top();
        pq.pop();
        if (cur == e)
            return cur_cost;

        for (auto &[cost, dest] : graph[cur])
        {
            if (d[dest] > cur_cost + cost)
            {
                d[dest] = cur_cost + cost;
                pq.emplace(d[dest], dest);
            }
        }
    }
    exit(-1);
}

bool solve()
{
    auto pass = dijkstra(1, v);
    auto with = dijkstra(1, p) + dijkstra(p, v);
    return pass == with;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << (solve() ? "SAVE HIM" : "GOOD BYE") << '\n';
}