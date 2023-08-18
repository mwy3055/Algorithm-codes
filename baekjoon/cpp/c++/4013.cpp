#include <bits/stdc++.h>

using pii = std::pair<int, int>;
using vi = std::vector<int>;

std::vector<vi> graph, scc_graph;
vi money, nth, visit, scc_no, scc_money, scc_rest, scc_maxval;
std::stack<int> s;
std::vector<bool> rest, scc_visit;
int nthval = 1, sccno;

void init(int &n)
{
    graph.resize(n + 1);
    scc_graph.resize(n + 1);
    money.resize(n + 1);
    nth.resize(n + 1);
    visit.resize(n + 1);
    scc_no.resize(n + 1);
    scc_money.resize(n + 1);
    scc_rest.resize(n + 1);
    scc_maxval.resize(n + 1);
    rest.resize(n + 1, false);
    scc_visit.resize(n + 1, false);
}
void getinput(int &n, int &m, int &s, int &p)
{
    std::cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> money[i];
    }
    std::cin >> s >> p;
    for (int i = 0; i < p; i++)
    {
        int ic;
        std::cin >> ic;
        rest[ic] = true;
    }
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
        int top = 0;
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

int search(int start) // search scc with priority queue. Also solvable with topology sort
{
    std::priority_queue<pii> pq;

    int ans = 0;
    pq.push(pii(scc_money[start], start));
    scc_maxval[start] = scc_money[start];
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        auto &money = top.first, &cur = top.second;
        if (scc_rest[cur])
        {
            ans = std::max(ans, money);
        }

        for (auto &adj : scc_graph[cur])
        {
            if (scc_maxval[adj] < money + scc_money[adj])
            {
                pq.push(pii(money + scc_money[adj], adj));
                scc_maxval[adj] = money + scc_money[adj];
            }
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, s, p;
    getinput(n, m, s, p);

    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 0)
            dfs(i);
    }

    // make scc graph
    for (int i = 1; i <= n; i++)
    {
        if (rest[i])
            scc_rest[scc_no[i]] = true;
        scc_money[scc_no[i]] += money[i];
        for (auto &adj : graph[i])
        {
            if (scc_no[i] != scc_no[adj])
            {
                scc_graph[scc_no[i]].push_back(scc_no[adj]);
            }
        }
    }
    std::cout << search(scc_no[s]) << '\n';
}