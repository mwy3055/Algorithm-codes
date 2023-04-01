#include <bits/stdc++.h>

int n, s, d;
int max_dep[100001];
std::vector<int> graph[100001];
bool visit[100001];

void getinput()
{
    std::cin >> n >> s >> d;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

int calc_dist(int cur)
{
    visit[cur] = true;

    auto &ret = max_dep[cur];
    for (auto &child : graph[cur])
    {
        if (!visit[child])
            ret = std::max(ret, calc_dist(child) + 1);
    }
    return ret;
}

// cur에서 출발하여 자식 노드를 탐색할 때 이동해야 하는 최소 거리
int solve(int cur)
{
    visit[cur] = true;
    int ans = 0;
    for (auto &child : graph[cur])
    {
        if (visit[child] || max_dep[child] < d)
            continue;
        auto dist = solve(child);
        ans += dist + 2;
    }
    return ans;
}

int solve()
{
    calc_dist(s);
    std::memset(visit, 0, sizeof(visit));
    return solve(s);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}