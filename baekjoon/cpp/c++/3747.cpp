#include <bits/stdc++.h>

using vi = std::vector<int>;
std::vector<vi> graph;
vi nth, visit, scc_no;
std::stack<int> s;
int nthval, sccno, n, m;

void init()
{
    graph.clear();
    nth.clear();
    visit.clear();
    scc_no.clear();
    while (!s.empty())
        s.pop();
    nthval = sccno = 0;

    int siz = 2 * n + 1;
    graph.resize(siz);
    nth.resize(siz);
    visit.resize(siz);
    scc_no.resize(siz);
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
            visit[top] = 2;
            scc_no[top] = sccno;
        }
        sccno++;
    }
    return parent;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while (std::cin >> n)
    {
        std::cin >> m;
        init();
        for (int a = 0; a < m; a++)
        {
            int i, j;
            std::cin >> i >> j;
            graph[neg(i)].push_back(pos(j));
            graph[neg(j)].push_back(pos(i));
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
}