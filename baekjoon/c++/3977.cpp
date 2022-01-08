#include <bits/stdc++.h>

std::vector<std::vector<int>> graph(100000), sgraph(100000);
std::stack<int> s;
int nthval, scc_count;
std::vector<int> nth(100000), sccno(100000), enter(100000), sccenter(100000), visit(100000);

void init()
{
    nthval = 1;
    scc_count = 0;
    for (auto &g : graph)
        g.clear();
    for (auto &g : sgraph)
        g.clear();
    while (!s.empty())
        s.pop();
    std::fill(nth.begin(), nth.end(), 0);
    std::fill(sccno.begin(), sccno.end(), 0);
    std::fill(sccenter.begin(), sccenter.end(), 0);
    std::fill(enter.begin(), enter.end(), 0);
    std::fill(visit.begin(), visit.end(), 0);
}

int dfs(int cur)
{
    nth[cur] = nthval++;
    s.push(cur);

    int parent = nth[cur];
    for (auto &adj : graph[cur])
    {
        if (nth[adj] == 0)
            parent = std::min(parent, dfs(adj));
        else if (!visit[adj])
            parent = std::min(parent, nth[adj]);
    }

    if (parent == nth[cur])
    {
        int top = -1;
        while (!s.empty() && top != cur)
        {
            top = s.top();
            s.pop();
            visit[top] = 1;
            sccno[top] = scc_count;
        }
        scc_count++;
    }
    return parent;
}

bool topology_sort(std::vector<int> &ans, int &n)
{
    std::queue<int> q;

    for (int i = 0; i < scc_count; i++)
    {
        if (sccenter[i] == 0)
            q.push(i);
    }
    if (q.size() > 1)
        return false;

    for (int i = 0; i < n; i++)
    {
        if (sccno[i] == q.front())
        {
            ans.push_back(i);
        }
    }
    for (int i = 0; i < scc_count; i++)
    {
        if (q.empty())
            return false;
        int top = q.front();
        q.pop();
        for (auto &adj : sgraph[top])
        {
            if (--sccenter[adj] == 0)
            {
                q.push(adj);
            }
        }
    }
    return true;
}

void solve()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
    }

    // find scc
    for (int i = 0; i < n; i++)
    {
        if (nth[i] == 0)
        {
            dfs(i);
        }
    }

    // make graph of scc
    for (int i = 0; i < n; i++)
    {
        for (auto &adj : graph[i])
        {
            if (sccno[i] != sccno[adj])
            {
                sgraph[sccno[i]].push_back(sccno[adj]);
                sccenter[sccno[adj]]++;
            }
        }
    }

    // topology sort of scc
    std::vector<int> ans;
    if (topology_sort(ans, n))
    {
        for (auto &a : ans)
            std::cout << a << '\n';
    }
    else
    {
        std::cout << "Confused" << '\n';
    }
    std::cout << '\n';
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
        solve();
    }
}