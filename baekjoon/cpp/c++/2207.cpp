#include <bits/stdc++.h>

using vi = std::vector<int>;
std::vector<vi> graph; // [1, m]: scissor, [m + 1, 2 * m]: rock
vi nth, visit, scc_no;
std::stack<int> s;
int n, m;
int nthval, sccno;

void init()
{
    graph.resize(2 * m + 1);
    nth.resize(2 * m + 1);
    visit.resize(2 * m + 1);
    scc_no.resize(2 * m + 1);
}

int pos(int i)
{
    if (i < 0)
        return -i + m;
    else
        return i;
}
int neg(int i)
{
    int rtn = (pos(i) + m - 1) % (m * 2) + 1;
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
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        graph[neg(x)].push_back(pos(y));
        graph[neg(y)].push_back(pos(x));
    }

    for (int i = 1; i <= 2 * m; i++)
    {
        if (visit[i] == 0)
            dfs(i);
    }

    bool ans = true;
    for (int i = 1; i <= m; i++)
    {
        if (scc_no[i] == scc_no[i + m])
        {
            ans = false;
            break;
        }
    }
    if (ans)
        std::cout << "^_^";
    else
        std::cout << "OTL";
}