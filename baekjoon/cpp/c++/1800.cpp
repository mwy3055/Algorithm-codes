#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair<int, int>;
using edge = pii; // cost, dest

const ll INF = 1LL << 50;

int n, p, k;
std::vector<edge> graph[1001];

void getinput()
{
    std::cin >> n >> p >> k;
    for (int i = 0; i < p; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
        graph[b].emplace_back(c, a);
    }
}

bool answer_exists()
{
    std::vector<bool> visit(n + 1, false);
    std::queue<int> q;

    q.push(1);
    visit[1] = true;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if (cur == n)
            return true;

        for (auto &[cost, dest] : graph[cur])
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

bool can(ll limit)
{
    // 가격이 limit 이상인 간선을 k개 이하로 사용하여
    // N번 학생에게 도달할 수 있는가?
    // dist: 가격이 limit 이상인 간선을 사용한 횟수
    // dist[n] <= k이면 limit이 정답의 후보가 될 수 있다.
    std::vector<ll> dist(n + 1, INF);
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq; // count, dest

    pq.emplace(0, 1);
    dist[1] = 0;
    while (!pq.empty())
    {
        auto [count, cur] = pq.top();
        pq.pop();

        if (dist[cur] < count)
            continue;
        for (auto &[cost, dest] : graph[cur])
        {
            auto ncost = count + (cost > limit);
            if (ncost < dist[dest])
            {
                pq.emplace(ncost, dest);
                dist[dest] = ncost;
            }
        }
    }

    return dist[n] <= k;
}

long long solve()
{
    if (!answer_exists())
        return -1;

    ll l = 0, r = INF; // [l, r]
    while (l + 1 <= r)
    {
        auto mid = (l + r) / 2;
        if (can(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}