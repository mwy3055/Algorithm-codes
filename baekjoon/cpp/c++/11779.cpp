#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // cost, node
const int INF = 100000 * 1010;
int n;
vector<pii> adj[1001];

void init(int *d)
{
    for (int i = 0; i <= n; i++)
        d[i] = INF;
}
void dijkstra(int s, int e)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int d[n + 1], prev[n + 1] = {0};
    init(d);

    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        auto cost = top.first, node = top.second;

        for (auto &bus : adj[node])
        {
            auto bcost = bus.first, dest = bus.second;
            int newcost = cost + bcost;
            if (newcost < d[dest])
            {
                d[dest] = newcost;
                prev[dest] = node;
                pq.push({newcost, dest});
            }
        }
    }

    stack<int> st;
    int cur = e;
    while (cur)
    {
        st.push(cur);
        cur = prev[cur];
    };

    cout << d[e] << '\n'
         << st.size() << '\n';
    while (!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    int s, e;
    cin >> s >> e;
    if (s == e)
    {
        cout << 0 << '\n'
             << 1 << '\n'
             << s;
        return 0;
    }
    dijkstra(s, e);
}