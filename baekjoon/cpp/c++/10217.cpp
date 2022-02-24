#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> Pair; // dist, cost, dest

const int INF = 0x5f3f3f3f;

int dijk(vector<vector<Pair>> &adj, const int &n, const int &m)
{
    int dp[n + 1][m + 1] = {0};
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = INF;

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.push({0, {0, 1}});
    while (!pq.empty())
    {
        Pair top = pq.top();
        pq.pop();
        int curDist = top.first, curCost = top.second.first, curNode = top.second.second;

        for (auto &edge : adj[curNode])
        {
            int &dist = edge.first, &cost = edge.second.first, &dest = edge.second.second;
            if (m < curCost + cost)
                continue;

            int &oldDist = dp[dest][curCost + cost], newDist = dp[curNode][curCost] + dist;
            if (newDist < oldDist)
            {
                oldDist = newDist;
                pq.push({newDist, {curCost + cost, dest}});
            }
        }
    }

    int ans = INF;
    for (int i = 0; i <= m; i++)
    {
        ans = min(ans, dp[n][i]);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<Pair>> adj(n + 1, vector<Pair>()); // dist, cost, dest
        for (int i = 0; i < k; i++)
        {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            adj[u].push_back({d, {c, v}});
        }

        int ans = dijk(adj, n, m);
        if (ans == INF)
            cout << "Poor KCM" << '\n';
        else
            cout << ans << '\n';
    }
}
