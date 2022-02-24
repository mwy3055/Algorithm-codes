#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> edge; // cost, dest

int n, m, x[3];
vector<vector<edge>> graph(1001, vector<edge>());
set<edge> ansedge; // node 1, node 2
int d[3][1001], ans;
edge tr[3][1001];

void init()
{
    for (int i = 0; i < 3; i++)
    {
        memset(d + i, 0x6f, sizeof(int) * 1001);
        for (int j = 0; j <= 1000; j++)
        {
            tr[i][j] = {0, j};
        }
    }
}
void solve(int idx)
{
    int &start = x[idx];
    priority_queue<edge, vector<edge>, greater<edge>> pq;

    d[idx][start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        auto top = pq.top();
        auto &ccost = top.first, &cnode = top.second; // current cost, current node
        pq.pop();

        for (auto &e : graph[cnode])
        {
            auto &cost = e.first, &dest = e.second;
            if (ccost + cost < d[idx][dest])
            {
                d[idx][dest] = ccost + cost;
                pq.push({d[idx][dest], dest});
                tr[idx][dest] = {cost, cnode};
            }
        }
    }
}
int getjunc() // gets last common point of each route, x[0]->x[1], x[0]->x[2]
{
    int idx = 0, ans = 0x6f6f6f6f;
    for (int i = 1; i <= n; i++)
    {
        if (d[0][i] + d[1][i] + d[2][i] < ans)
        {
            ans = d[0][i] + d[1][i] + d[2][i];
            idx = i;
        }
    }
    return idx;
}
void track(int idx, int junc)
{
    int cur = junc;
    while (cur != x[idx] && cur != tr[idx][cur].second)
    {
        int a = cur, b = tr[idx][cur].second;
        if (a > b)
            swap(a, b);
        if (ansedge.find({a, b}) == ansedge.end())
        {
            ansedge.insert({a, b});
            ans += tr[idx][cur].first;
        }
        cur = tr[idx][cur].second;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    cin >> x[0] >> x[1] >> x[2];

    for (int i = 0; i < 3; i++)
        solve(i);

    int junc = getjunc();
    for (int i = 0; i < 3; i++)
        track(i, junc);
    cout << ans << ' ' << ansedge.size() << '\n';
    for (auto &e : ansedge)
        cout << e.first << ' ' << e.second << '\n';
}