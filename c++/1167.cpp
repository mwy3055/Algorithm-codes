#include <bits/stdc++.h>
using namespace std;

#define dst first
#define dist second
const int INF = 1e9;
using Pair = pair<int, int>;

int bfs(int &v, vector<vector<Pair>> &adj)
{
    bool visit[v + 1] = {false};
    int d[v + 1] = {0};
    queue<int> q;

    d[1] = 0;
    visit[1] = true;
    q.push(1);

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        for (auto &next : adj[top])
        {
            if (visit[next.dst])
                continue;

            d[next.dst] = d[top] + next.dist;
            visit[next.dst] = true;
            q.push(next.dst);
        }
    }

    int ans = 0;
    for (int i = 2; i <= v; i++)
        if (ans < d[i])
            ans = d[i];
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v;
    cin >> v;
    vector<vector<Pair>> adj(v + 1);

    for (int i = 1; i <= v; i++)
    {
        while (true)
        {
            int a, b;
            cin >> a;
            if (a == i)
                continue;
            else if (a == -1)
                break;

            cin >> b;
            adj[a].push_back(Pair(i, b));
            adj[i].push_back(Pair(a, b));
        }
    }

    cout << bfs(v, adj);
}