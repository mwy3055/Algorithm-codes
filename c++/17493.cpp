#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
int n, m;
std::vector<int> graph[200001], tree[200001];
int dp[200001][3];
bool tvisit[200001], svisit[200001];

void maketree(int cur)
{
    tvisit[cur] = true;
    for (auto &adj : graph[cur])
    {
        if (!tvisit[adj])
        {
            tree[cur].push_back(adj);
            maketree(adj);
        }
    }
}

// 0: node is selected
// 1: node is not selected but at least one adjacent node is selected
// 2: node is not selected nor all adjacent nodes are selected
int search(int cur)
{
    svisit[cur] = true;

    int d = INF;
    dp[cur][0] = 1;
    for (auto &adj : tree[cur])
    {
        search(adj);
        int mval = std::min(dp[adj][0], dp[adj][1]);
        dp[cur][0] += std::min(mval, dp[adj][2]);
        dp[cur][1] += mval;
        dp[cur][2] = std::min(INF, dp[cur][2] + dp[adj][1]);
        d = std::min(d, dp[adj][0] - mval);
    }
    dp[cur][1] = std::min(INF, dp[cur][1] + d);

    return std::min(dp[cur][0], dp[cur][1]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!tvisit[i])
            maketree(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!svisit[i])
        {
            ans += search(i);
        }
    }
    std::cout << ans;
}