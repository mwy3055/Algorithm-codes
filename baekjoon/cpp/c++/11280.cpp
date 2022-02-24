#include <bits/stdc++.h>

using vi = std::vector<int>;
std::vector<vi> graph;
vi nth, visit, scc_no;
std::stack<int> s;
int n, m;
int nthval, sccno;

void init()
{
    graph.resize(2 * (n + 1));
    nth.resize(2 * (n + 1));
    visit.resize(2 * (n + 1));
    scc_no.resize(2 * (n + 1));
}

int pos(int i)
{
    if (i < 0)
        return -i + n;
    else
        return i;
}
int neg(int i)
{
    int rtn = (pos(i) + n - 1) % (n * 2) + 1;
    return rtn;
}

int dfs(int cur)
{
    nth[cur] = nthval++;
    visit[cur] = 1;
    s.push(cur);

    int parent = nth[cur];
    for (auto &adj : graph[cur])
    {
        if (visit[adj] == 0)
            parent = std::min(parent, dfs(adj));
        else if (visit[adj] == 1)
            parent = std::min(parent, nth[adj]);
    }

    if (parent == nth[cur])
    {
        int top = -1;
        while (!s.empty() && top != cur)
        {
            top = s.top();
            s.pop();
            scc_no[top] = sccno;
            visit[top] = 2;
        }
        sccno++;
    }
    return parent;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m;
    init();
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[neg(a)].push_back(pos(b));
        graph[neg(b)].push_back(pos(a));
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        if (visit[i] == 0)
            dfs(i);
    }

    bool ans = true;
    for (int i = 1; i <= n; i++)
    {
        if (scc_no[i] == scc_no[i + n])
        {
            ans = false;
            break;
        }
    }
    std::cout << ans << '\n';
}