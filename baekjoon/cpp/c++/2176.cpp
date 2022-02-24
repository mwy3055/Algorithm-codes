#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 0x7f7f7f7f;
int n, m, dist[1001], dp[1001];
vector<pii> graph[1001]; // cost, dest

void dijk(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[s] = 0;
    pq.push(pii(0, s));
    while (!pq.empty())
    {
        auto top = pq.top();
        auto &curdist = top.first, &cur = top.second;
        pq.pop();

        for (auto &edge : graph[cur])
        {
            int newdist = curdist + edge.first, &dest = edge.second;
            if (newdist < dist[dest])
            {
                dist[dest] = newdist;
                pq.push(pii(newdist, dest));
            }
        }
    }
}
int dfs(int cur)
{
    int &ret = dp[cur];
    if (cur == 2)
        return ret = 1;
    if (ret)
        return ret;

    for (auto &edge : graph[cur])
    {
        auto &child = edge.second;
        if (dist[cur] > dist[child])
            ret += dfs(child);
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(pii(c, b));
        graph[b].push_back(pii(c, a));
    }
    dijk(2);

    cout << dfs(1);
}