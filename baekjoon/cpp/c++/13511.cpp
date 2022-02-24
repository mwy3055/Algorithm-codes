#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, ll> pii; // dest, cost
const int MAX_DEP = 19;

std::vector<pii> graph[100001];
int depth[100001], parent[100001][MAX_DEP + 1];
ll dist[100001]; // from node 1 to i
bool visit[100001];

void bfs()
{
    std::queue<int> q;

    visit[1] = true;
    q.push(1);
    int dep = 1;
    while (!q.empty())
    {
        int siz = q.size();
        while (siz--)
        {
            auto top = q.front();
            q.pop();
            depth[top] = dep;

            for (auto &v : graph[top])
            {
                auto &dest = v.first;
                auto &cost = v.second;
                if (!visit[dest])
                {
                    visit[dest] = true;
                    q.push(dest);
                    parent[dest][0] = top;
                    dist[dest] = dist[top] + cost;
                }
            }
        }
        dep++;
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

ll query1(int u, int v)
{
    int lca = LCA(u, v);
    return dist[u] + dist[v] - 2 * dist[lca];
}

int query2(int u, int v, int k) // u -> v
{
    int lca = LCA(u, v);
    int diff_ul = depth[u] - depth[lca], diff_vl = depth[v] - depth[lca];
    int cur, left; // 움직여야 하는 횟수

    if (k <= diff_ul + 1)
    {
        cur = u, left = k - 1;
    }
    else
    {
        cur = v, left = (diff_vl + 1) - (k - diff_ul);
    }

    for (int i = MAX_DEP; i >= 0; i--)
    {
        if ((1 << i) <= left)
        {
            cur = parent[cur][i];
            left -= (1 << i);
        }
    }
    return cur;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    bfs();
    preprocess(n);

    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        int q;
        std::cin >> q;
        if (q == 1)
        {
            int u, v;
            std::cin >> u >> v;
            std::cout << query1(u, v) << '\n';
        }
        else if (q == 2)
        {
            int u, v, k;
            std::cin >> u >> v >> k;
            std::cout << query2(u, v, k) << '\n';
        }
    }
}