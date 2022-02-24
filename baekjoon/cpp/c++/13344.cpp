#include <bits/stdc++.h>
const int MAX = 50000;
typedef std::pair<int, int> pii;
std::vector<int> graph[MAX + 1];
int visit[MAX + 1];

int root[MAX + 1];
void init()
{
    for (int i = 0; i <= MAX; i++)
        root[i] = -1;
}
int find(int n)
{
    if (root[n] < 0)
        return n;
    return root[n] = find(root[n]);
}
void union_vertex(int a, int b)
{
    int root1 = find(a), root2 = find(b);
    if (root1 == root2)
        return;

    if (root[root1] > root[root2])
        std::swap(root1, root2);

    root[root1] += root[root2];
    root[root2] = root1;
}

// true: inconsistent
// false: consistent
bool dfs(int cur, int start)
{
    if (visit[cur])
    {
        return visit[cur] == 1;
    }

    visit[cur] = 1; // 1: search not ended
    for (auto &child : graph[cur])
    {
        if (dfs(child, cur))
            return true;
    }
    visit[cur] = 2; // 2: search ended
    return false;
}

int n;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    init();

    int m;
    std::cin >> n >> m;
    std::vector<pii> vp;
    for (int i = 0; i < m; i++)
    {
        int k, l;
        char op;
        std::cin >> k >> op >> l;
        if (op == '=')
            union_vertex(k, l);
        else
            vp.push_back(pii(k, l));
    }
    for (auto &p : vp)
    {
        auto k = find(p.first), l = find(p.second);
        graph[k].push_back(l);
    }

    bool result = false;
    for (int i = 0; i < n; i++)
    {
        result |= dfs(i, i);
        if (result)
            break;
    }
    if (result)
        std::cout << "inconsistent" << '\n';
    else
        std::cout << "consistent" << '\n';
}