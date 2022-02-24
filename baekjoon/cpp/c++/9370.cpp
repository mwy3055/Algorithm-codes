// g~h 경로를 경유했는지 어떻게 알 수 있을까?
// 모든 경로의 비용을 2배로 늘린다. 이때 g~h 경로만 여기서 -1을 해 준다.
// 후보지까지 가는 비용이 홀수라면 g~h를 경유한 것이다.
// 최단 경로가 여러 개인 경우를 처리할 수 있다.

#include <bits/stdc++.h>
using namespace std;

typedef const int cint;

typedef pair<int, int> dijkNode;
#define Cost first
#define Node second

typedef pair<int, int> costDest;
#define Dest second

cint INF = 0x3f3f3f3f;

struct path
{
    int cost, prev;
};

void getinput(vector<vector<costDest>> &adjList, vector<int> &candidates, cint &m, cint &t, cint &g, cint &h)
{
    for (int i = 0; i < m; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        if ((a == g && b == h) || (a == h && b == g))
        {
            adjList[a].push_back({d * 2 - 1, b});
            adjList[b].push_back({d * 2 - 1, a});
        }
        else
        {
            adjList[a].push_back({d * 2, b});
            adjList[b].push_back({d * 2, a});
        }
    }
    for (int i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        candidates.push_back(x);
    }
}
void dijk(vector<vector<costDest>> &adjList, vector<int> &d, cint &s, cint &n)
{
    priority_queue<dijkNode, vector<dijkNode>, greater<dijkNode>> pq;

    d[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        dijkNode top = pq.top();
        pq.pop();
        int curNode = top.Node, curCost = top.Cost;

        for (auto &adj : adjList[curNode])
        {
            int dest = adj.Dest, cost = adj.Cost;
            int newCost = curCost + cost, &oldCost = d[dest];
            if (newCost < oldCost)
            {
                oldCost = newCost;
                pq.push({newCost, dest});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, t;
        cin >> n >> m >> t;
        int s, g, h;
        cin >> s >> g >> h;
        vector<vector<costDest>> adjList(n + 1, vector<costDest>());
        vector<int> candidates;
        getinput(adjList, candidates, m, t, g, h);

        vector<int> d(n + 1, INF);
        dijk(adjList, d, s, n);

        sort(candidates.begin(), candidates.end());
        for (int &candd : candidates)
        {
            if (d[candd] != INF && d[candd] % 2)
                cout << candd << ' ';
        }
        cout << '\n';
    }
}