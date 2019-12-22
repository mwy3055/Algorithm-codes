#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, pair<int, int>> pip; // cost, <start, dest>
typedef vector<pip> vp;

const int INF = 0x3f3f3f3f;

bool bellman_ford(vp &adj, int &n, int s)
{
    vector<int> d(n + 1, INF);
    d[s] = 0;
    for (int a = 1; a < n; a++)
    {
        for (auto &edge : adj)
        {
            int &cost = edge.first, &s = edge.second.first, &e = edge.second.second;
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
        int &cost = edge.first, &s = edge.second.first, &e = edge.second.second;
        if (d[e] != INF && d[s] + cost < d[e])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, w;
        cin >> n >> m >> w;
        vp adjList;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            adjList.push_back({c, {a, b}});
            adjList.push_back({c, {b, a}});
        }
        for (int i = 0; i < w; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            adjList.push_back({-c, {a, b}});
        }
        cout << (bellman_ford(adjList, n, 1) ? "NO" : "YES") << '\n';
    }
}