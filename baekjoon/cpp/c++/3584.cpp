#include <bits/stdc++.h>
const int MAX_DEP = 14;

bool visit[50001], isroot[50001];
int depth[50001], parent[50001][MAX_DEP + 1];

void init()
{
    std::fill(visit, visit + 50001, false);
    std::fill(isroot, isroot + 50001, true);
    std::fill(depth, depth + 50001, 0);
    for (int i = 0; i <= 50000; i++)
    {
        memset(parent[i], 0, sizeof(int) * (MAX_DEP + 1));
    }
}

void dfs(std::vector<std::vector<int>> &adj, int cur, int dep)
{
    visit[cur] = true;
    depth[cur] = dep;
    for (auto &node : adj[cur])
    {
        if (visit[node])
            continue;
        parent[node][0] = cur;
        dfs(adj, node, dep + 1);
    }
}
void preprocess(int n)
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
        std::swap(a, b);
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

int getroot(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (isroot[i])
            return i;
    }
    return 0;
}
int solve()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        isroot[b] = false;
    }
    int root = getroot(n);
    dfs(adj, root, 0);
    preprocess(n);

    int n1, n2;
    std::cin >> n1 >> n2;
    return LCA(n1, n2);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        init();
        std::cout << solve() << '\n';
    }
}