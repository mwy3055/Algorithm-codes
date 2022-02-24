#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, pair<int, int>> plp; // cost, <start, dest>
typedef vector<plp> vp;

const int INF = 0x6f3f3f3f;

bool bellman_ford(vp &adj, vector<ll> &d, int &n)
{
    d[1] = 0;
    for (int a = 1; a < n; a++)
    {
        for (auto &edge : adj)
        {
            auto &cost = edge.first;
            auto &s = edge.second.first, &e = edge.second.second;
            if (d[s] == INF)
                continue;
            else if (d[s] + cost < d[e])
            {
                d[e] = d[s] + cost;
            }
        }
    }

    for (auto &edge : adj)
    {
        auto &cost = edge.first;
        auto &s = edge.second.first, &e = edge.second.second;
        if (d[e] != INF && d[s] + cost < d[e])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vp adjList;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adjList.push_back({c, {a, b}});
    }

    vector<ll> d(n + 1, INF);
    if (!bellman_ford(adjList, d, n))
        cout << -1;
    else
    {
        for (int i = 2; i <= n; i++)
            cout << (d[i] == INF ? -1 : d[i]) << '\n';
    }
}