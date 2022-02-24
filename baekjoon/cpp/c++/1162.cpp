#include <bits/stdc++.h>

using ll = long long;
using edge = std::pair<int, int>;      // dest, dist
using node = std::tuple<ll, int, int>; // dist, node, 남은 포장 횟수

int n, m, k;
std::vector<edge> graph[10001];
// 다익스트라
// dist[i][j]: 도로를 j번 더 포장할 수 있을 때, 1번 도시에서 i번 도시까지의 최단 거리
ll dist[10001][21];
const ll INF = 0x3f3f3f3f3f3f3f;

void getinput()
{
    std::cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, cost;
        std::cin >> a >> b >> cost;
        graph[a].emplace_back(b, cost);
        graph[b].emplace_back(a, cost);
    }
}

ll solve()
{
    std::memset(dist, 0x3f, sizeof(dist));
    dist[1][k] = 0;

    std::priority_queue<node, std::vector<node>, std::greater<node>> pq;
    pq.push(node(0, 1, k));

    while (!pq.empty())
    {
        auto [d, node, left] = pq.top();
        pq.pop();
        if (d > dist[node][left])
            continue;

        for (auto &[next, cost] : graph[node])
        {
            // 이 도로를 포장?
            if (left > 0 && dist[next][left - 1] > d)
            {
                dist[next][left - 1] = d;
                pq.push({d, next, left - 1});
            }
            // 포장하지 않는 경우
            auto ndist = d + cost;
            if (dist[next][left] > ndist)
            {
                dist[next][left] = ndist;
                pq.push({ndist, next, left});
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i <= k; i++)
        ans = std::min(ans, dist[n][i]);
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}