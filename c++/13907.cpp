#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> src; // cost, path num, dest
int n, m, k, s, d, increased = 0, dist[1001][1001];
vector<vector<pii>> graph(1001, vector<pii>()); // cost, dest
vector<int> incr;

void getinput()
{
    cin >> n >> m >> k >> s >> d;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back(pii(w, b));
        graph[b].push_back(pii(w, a));
    }
    for (int i = 0; i < k; i++)
    {
        int p;
        cin >> p;
        incr.push_back(p);
    }
}

void dijk()
{
    priority_queue<src, vector<src>, greater<src>> pq;
    for (int i = 0; i <= 1000; i++)
        memset(dist + i, 0x6f, sizeof(int) * 1001);

    pq.push(src(0, pii(0, s)));
    memset(dist + s, 0, sizeof(int) * 1001);
    while (!pq.empty())
    {
        auto top = pq.top();
        int &curcost = top.first, &pnum = top.second.first, &cur = top.second.second;
        pq.pop();
        if (pnum > n || cur == d)
            continue;

        for (auto &edge : graph[cur])
        {
            int &cost = edge.first, &dest = edge.second;
            int newcost = dist[cur][pnum] + cost;
            bool promising = true;
            for (int i = 1; i <= pnum; i++)
            {
                if (dist[dest][i] < newcost) // not promising if it has more edge
                {
                    promising = false;
                    break;
                }
            }
            if (!promising)
                continue;
            if (newcost < dist[dest][pnum + 1])
            {
                pq.push(src(newcost, pii(pnum + 1, dest)));
                dist[dest][pnum + 1] = newcost;
            }
        }
    }
}
int solve()
{
    int ans = 0x6f6f6f6f;
    for (int i = 1; i <= 1000; i++)
        if (dist[d][i] + i * increased < ans)
            ans = dist[d][i] + i * increased;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    incr.push_back(0);
    getinput();
    dijk();
    for (auto &amount : incr)
    {
        increased += amount;
        cout << solve() << '\n';
    }
}