#include <bits/stdc++.h>

using pii = std::pair<int, int>; // cost, dest

int n, m;
std::vector<pii> graph[201];

void getinput()
{
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
        graph[b].emplace_back(c, a);
    }
}

double ignite(int start)
{
    // start에 불을 붙였을 때 그래프가 다 타는 데 걸리는 최소 시간
    // 일단 각 정점에 불이 언제 도착하는지 계산하자.
    std::vector<int> dist(n + 1, 0x3f3f3f3f);
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

    dist[start] = 0;
    pq.emplace(0, start);
    while (!pq.empty())
    {
        auto [cost, now] = pq.top();
        pq.pop();

        for (auto &[ecost, adj] : graph[now])
        {
            if (cost + ecost < dist[adj])
            {
                dist[adj] = cost + ecost;
                pq.emplace(dist[adj], adj);
            }
        }
    }

    // 이제 각 간선에 대해 이 간선이 언제 다 타는지 계산하자.
    double maxtime = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto &[cost, dest] : graph[i])
        {
            double time_diff = std::abs(dist[i] - dist[dest]);
            auto fire_time = std::min(dist[i], dist[dest]);
            if (cost > time_diff)
            {
                maxtime = std::max(maxtime, fire_time + time_diff + (cost - time_diff) / 2);
            }
            else
            {
                maxtime = std::max(maxtime, fire_time + (double)cost);
            }
        }
    }
    return maxtime;
}

double solve()
{
    double ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        auto temp = ignite(i);
        ans = std::min(ans, temp);
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout.precision(1);
    std::cout << std::fixed << solve() << '\n';
}