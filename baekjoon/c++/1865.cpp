#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, pair<int, int>> pip; // cost, <start, dest>
typedef vector<pip> vp;

const int INF = 0x3f3f3f3f;

bool bellman_ford(vp &adj, vector<bool> &visit, int &n, int s)
{
    vector<int> d(n + 1, INF);
    d[s] = 0;
    visit[s] = true;
    for (int a = 1; a < n; a++)
    {
        for (auto &edge : adj)
        {
            int &cost = edge.first, &s = edge.second.first, &e = edge.second.second;
            if (d[s] == INF)
                continue;
            else if (d[s] + cost < d[e])
            {
                visit[e] = true;
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

        bool ans = false;
        vector<bool> visit(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            if (!visit[i])
            {
                auto result = bellman_ford(adjList, visit, n, i);
                if (!result)
                {
                    ans = true;
                    break;
                }
            }
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
}