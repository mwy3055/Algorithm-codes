#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> Pair; // dest, cost
typedef pair<ll, ll> Ans;

const int MAX_NODE = 100000;
const int MAX_DEP = 17;

int n, m;
bool visit[MAX_NODE + 1];
int depth[MAX_NODE + 1], parent[MAX_NODE + 1][MAX_DEP + 1];
Ans answer[MAX_NODE + 1][MAX_DEP + 1];

Ans compare(Ans a, Ans b)
{
    return Ans(min(a.first, b.first), max(a.second, b.second));
}

void dfs(vector<vector<Pair>> &adj, int cur, int dep)
{
    visit[cur] = true;
    depth[cur] = dep;

    for (auto &edge : adj[cur])
    {
        int &node = edge.first, &cost = edge.second;
        if (visit[node])
            continue;
        parent[node][0] = cur;
        answer[node][0] = Ans(cost, cost);
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
            answer[i][j] = compare(answer[parent[i][j - 1]][j - 1], answer[i][j - 1]);
        }
    }
}

Ans LCA(int a, int b)
{
    Ans ans = Ans((ll)1 << 61, 0);
    // 항상 b가 더 깊은 정점이 되도록 함
    if (depth[a] > depth[b])
        swap(a, b);
    for (int i = MAX_DEP; i >= 0; i--)
    {
        if ((1 << i) <= depth[b] - depth[a])
        {
            ans = compare(ans, answer[b][i]);
            b = parent[b][i];
        }
    }
    if (a == b)
        return ans;

    for (int i = MAX_DEP; i >= 0; i--)
    {
        if (parent[a][i] != parent[b][i])
        {
            ans = compare(compare(ans, answer[a][i]), answer[b][i]);
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    ans = compare(compare(ans, answer[a][0]), answer[b][0]);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<vector<Pair>> adj(n + 1, vector<Pair>());
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(Pair(b, c));
        adj[b].push_back(Pair(a, c));
    }
    dfs(adj, 1, 0);
    preprocess();

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Ans pair = LCA(a, b);
        cout << pair.first << ' ' << pair.second << '\n';
    }
}