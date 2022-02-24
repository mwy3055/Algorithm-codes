#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> &adj, int *color, int i)
{
    queue<int> q;
    q.push(i);
    color[i] = 1;

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        int diffcolor = (color[top] == 1 ? 2 : 1);

        for (auto &node : adj[top])
        {
            if (color[top] == color[node])
                return false;

            if (color[node] == 0)
            {
                color[node] = diffcolor;
                q.push(node);
            }
        }
    }
    return true;
}

bool isbipartite(vector<vector<int>> &adj, int &n)
{
    //방문 상태. 0: 미방문, 1: 그룹 1에 속함, 2: 그룹 2에 속함
    int color[n + 1] = {0};

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0 && !bfs(adj, color, i))
            return false;
    }

    return true;
}

bool solve()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v + 1, vector<int>());
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    adj[0].push_back(0);
    return isbipartite(adj, v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;
    while (k--)
        cout << (solve() ? "YES" : "NO") << '\n';
}