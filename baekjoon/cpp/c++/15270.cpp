#include <bits/stdc++.h>

using vi = std::vector<int>;
vi graph[21];
std::vector<bool> paired(21);
int ans = 0;

void dfs(int cur, int &n, int pair)
{
    if (cur == n + 1)
    {
        ans = std::max(ans, pair * 2);
        return;
    }

    if (!paired[cur])
    {
        for (auto &f : graph[cur])
        {
            if (!paired[f])
            {
                paired[cur] = true;
                paired[f] = true;
                dfs(cur + 1, n, pair + 1);
                paired[cur] = false;
                paired[f] = false;
            }
        }
    }
    dfs(cur + 1, n, pair);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, n, 0);
    if (ans < n)
        ans++;
    std::cout << ans << '\n';
}