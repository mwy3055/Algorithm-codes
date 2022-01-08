#include <bits/stdc++.h>

std::vector<std::vector<int>> graph(100001);
std::stack<int> s;
int nthval, scc_count;
std::vector<int> nth(100001), sccno(100001), enter(100001), sccenter(100001), visit(100001);

void init()
{
    nthval = 1;
    scc_count = 0;
    for (auto &g : graph)
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
        int top = 0;
        while (!s.empty() && top != cur)
        {
            top = s.top();
            s.pop();
            visit[top] = true;
            sccno[top] = scc_count;
        }
        scc_count++;
    }
    return parent;
}
int solve()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
        enter[y]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (nth[i] == 0)
            dfs(i);
    }

    // SCC의 위상 정렬
    for (int i = 1; i <= n; i++)
    {
        for (auto &adj : graph[i])
        {
            if (sccno[i] != sccno[adj])
            {
                sccenter[sccno[adj]]++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < scc_count; i++)
    {
        if (sccenter[i] == 0)
        {
            ans++;
        }
    }
    return ans;
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