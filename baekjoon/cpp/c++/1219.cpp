#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair<int, int>; // dest, cost
struct edge
{
    int s, e, cost;
    edge(int s, int e, int cost) : s(s), e(e), cost(cost) {}
};
const ll INF = 1LL << 60;

int n, start, end, m;

ll cost[100][100], city[100];
std::vector<pii> graph[100];
std::vector<edge> edges;

bool cango[100][100];
ll dist[100];

void getinput()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
            cost[i][j] = INF;
    }

    std::cin >> n >> start >> end >> m;
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        std::cin >> a >> b >> c;
        cost[a][b] = std::min(cost[a][b], c);
        cango[a][b] = true;
    }

    for (int i = 0; i < n; i++)
        std::cin >> city[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cost[i][j] != INF)
            {
                // 음수 사이클(돈이 무한히 늘어나는 상황)을 찾기 위해 부호를 반대로
                auto c = cost[i][j] - city[j];
                graph[i].emplace_back(j, c);
                edges.emplace_back(i, j, c);
            }
        }
    }
}

bool possible()
{
    // 도착 도시에 도착할 수 있는가?
    bool visit[100] = {false};
    std::queue<int> q;

    q.push(start);
    visit[start] = true;
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();

        if (top == end)
            return true;
        for (auto &[dest, cost] : graph[top])
        {
            if (!visit[dest])
            {
                q.push(dest);
                visit[dest] = true;
            }
        }
    }
    return false;
}

ll solve()
{
    // 플로이드 와샬
    for (int i = 0; i < n; i++)
        cango[i][i] = true;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && i != k && j != k)
                {
                    cango[i][j] |= cango[i][k] && cango[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
    }

    dist[start] = -city[start];
    for (int i = 1; i < n; i++)
    {
        for (auto &[s, e, cost] : edges)
        {
            if (dist[s] != INF && dist[s] + cost < dist[e])
            {
                dist[e] = dist[s] + cost;
            }
        }
    }

    // 음수 사이클(돈이 무한히 늘어나는 경로)이지만 출발점 -> i -> 도착점 경로가
    // 불가능하다면 의미가 없다.
    for (int i = 0; i < n; i++)
    {
        for (auto &[dest, cost] : graph[i])
        {
            if (dist[i] + cost < dist[dest] && cango[start][i] && cango[i][end])
                return INF;
        }
    }

    return -dist[end];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();

    auto ans = solve();
    if (ans == INF)
        std::cout << "Gee" << '\n';
    else if (ans == -INF)
        std::cout << "gg" << '\n';
    else
        std::cout << ans << '\n';
}