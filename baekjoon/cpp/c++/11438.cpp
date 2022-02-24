#include <bits/stdc++.h>
using namespace std;

const int MAX_NODE = 100000;
const int MAX_DEP = 18;
int n, m;

bool visited[MAX_NODE + 1];
int depth[MAX_NODE + 1], parent[MAX_NODE + 1][MAX_DEP + 1];
void dfs(vector<vector<int>> &adj, int cur, int dep)
{
    visited[cur] = true;
    depth[cur] = dep;
    for (auto &node : adj[cur])
    {
        if (visited[node])
            continue;
        parent[node][0] = cur;
        dfs(adj, node, dep + 1);
    }
}
void preprocess()
{
    for (int j = 1; j <= MAX_DEP; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int LCA(int a, int b)
{
    // 항상 b가 더 깊은 정점이 되도록 함
    if (depth[a] > depth[b])
        swap(a, b);
    for (int i = MAX_DEP; i >= 0; i--)
    {
        if ((1 << i) <= depth[b] - depth[a])
        {
            b = parent[b][i];
        }
    }
    if (a == b)
        return a;

    for (int i = MAX_DEP; i >= 0; i--)
    {
        if (parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(adj, 1, 0);
    preprocess();

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }
}