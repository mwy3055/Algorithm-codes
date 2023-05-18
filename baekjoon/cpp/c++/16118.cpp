#include <bits/stdc++.h>

using ll = long long;
using edge = std::pair<ll, int>;                   // dist, dest
using node = std::pair<ll, int>;                   // current cost(dist), current position
using wnode = std::pair<ll, std::pair<int, bool>>; // cur cost, cur pos, cur state (run/walk)

const ll INF = 1LL << 60;
int n, m;
std::vector<edge> graph[4001];
ll fdist[4001], wdist[2][4001];

void getinput()
{
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, d;
        std::cin >> a >> b >> d;
        graph[a].emplace_back(d * 2, b);
        graph[b].emplace_back(d * 2, a);
    }
}

void run_fox()
{
    std::priority_queue<node, std::vector<node>, std::greater<node>> pq;
    std::memset(fdist, 0x3f, sizeof(fdist));

    fdist[1] = 0;
    pq.emplace(0, 1);
    while (!pq.empty())
    {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cost > fdist[cur])
            continue;

        for (auto &[ncost, dest] : graph[cur])
        {
            if (cost + ncost < fdist[dest])
            {
                fdist[dest] = cost + ncost;
                pq.emplace(cost + ncost, dest);
            }
        }
    }
}

void run_wolf()
{
    std::priority_queue<wnode, std::vector<wnode>, std::greater<wnode>> pq;
    std::memset(wdist, 0x3f, sizeof(wdist));

    // true: run, false: walk
    // wdist[0][1] = wdist[1][1] = 0을 하면 안 되는 이유
    // 1에서 출발하여 돌다가 다시 1로 돌아온 후, 느리게 걸어나가는 경로가 최적일 수도 있음
    pq.emplace(0, std::make_pair(1, false));

    while (!pq.empty())
    {
        auto top = pq.top();
        ll cost = top.first, cur = top.second.first;
        auto state = top.second.second;
        pq.pop();

        if (cost > wdist[state][cur])
            continue;

        auto nstate = !state;
        for (auto &[ncost, dest] : graph[cur])
        {
            auto speed = nstate ? ncost / 2 : ncost * 2;
            if (cost + speed < wdist[nstate][dest])
            {
                wdist[nstate][dest] = cost + speed;
                pq.emplace(cost + speed, std::make_pair(dest, nstate));
            }
        }
    }
}

int solve()
{
    run_fox();
    run_wolf();

    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (fdist[i] < std::min(wdist[0][i], wdist[1][i]))
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}