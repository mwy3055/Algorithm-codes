#include <bits/stdc++.h>

using edge = std::pair<int, int>; // cost, dest
using node = std::pair<int, int>; // cost, cur

int n, m, start, end;
int mdist[1001][1001];
std::vector<edge> graph[1001];

const int INF = 0x3f3f3f3f;

void getinput()
{
    std::memset(mdist, 0x3f, sizeof(mdist));
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        mdist[a][b] = std::min(mdist[a][b], c);
    }
    std::cin >> start >> end;
}

void make_graph()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mdist[i][j] != INF)
            {
                graph[i].emplace_back(mdist[i][j], j);
            }
        }
    }
}

int solve()
{
    make_graph();
    std::vector<int> d(n + 1, INF);
    std::priority_queue<node, std::vector<node>, std::greater<node>> pq;

    d[start] = 0;
    pq.emplace(0, start);
    while (!pq.empty())
    {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (d[cur] < cost)
            continue;
        if (cur == end)
            return cost;

        for (auto &[ecost, next] : graph[cur])
        {
            int ncost = cost + ecost;
            if (d[next] > ncost)
            {
                d[next] = ncost;
                pq.emplace(ncost, next);
            }
        }
    }
    exit(-1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}