#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, vector<vector<int>> &adj, int *parent, bool *visit)
{
    for (auto &next : adj[cur])
    {
        if (!visit[next])
        {
            visit[next] = true;
            parent[next] = cur;
            dfs(next, adj, parent, visit);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    bool visit[n + 1] = {false};
    int parent[n + 1];
    vector<vector<int>> adj(n + 1, vector<int>());

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visit[1] = true;
    parent[1] = 0;
    dfs(1, adj, parent, visit);

    for (int i = 2; i <= n; i++)
        cout << parent[i] << '\n';
}