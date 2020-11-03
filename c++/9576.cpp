#include <bits/stdc++.h>

using vi = std::vector<int>;

std::vector<bool> visit(1001);
std::vector<vi> graph(1001);
vi track(1001);

bool dfs(int cur)
{
    for (auto &adj : graph[cur])
    {
        if (visit[adj])
            continue;
        visit[adj] = true;
        if (track[adj] == 0 || dfs(track[adj]))
        {
            track[adj] = cur;
            return true;
        }
    }
    return false;
}
void init()
{
    for (auto &g : graph)
        g.clear();
    std::fill(track.begin(), track.end(), 0);
}
int solve()
{
    int n, m;
    std::cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        for (int j = a; j <= b; j++)
            graph[i].push_back(j);
    }

    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        std::fill(visit.begin(), visit.end(), false);
        if (dfs(i))
            ans++;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        std::cout << solve() << '\n';
    }
}