#include <bits/stdc++.h>
using namespace std;

using Pair = pair<int, int>;

//임의의 정점(여기서는 1번)에서 가장 멀리 있는 정점 B를 구한다.
//B로부터 가장 멀리 있는 정점까지의 거리가 트리의 지름이다.

int bfs(int &v, int start, vector<vector<Pair>> &adj, int &ans)
{
    bool visit[v + 1] = {false};
    int d[v + 1] = {0};
    queue<int> q;

    d[start] = 0;
    visit[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        for (auto &next : adj[top])
        {
            int &dst = next.first, &dist = next.second;
            if (visit[dst])
                continue;

            d[dst] = d[top] + dist;
            visit[dst] = true;
            q.push(dst);
        }
    }

    int maxi = 1;
    for (int i = 2; i <= v; i++)
    {
        if (d[maxi] < d[i])
            maxi = i;
    }
    ans = d[maxi];
    return maxi;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v;
    cin >> v;
    vector<vector<Pair>> adj(v + 1, vector<Pair>());

    for (int i = 0; i < v - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(Pair(b, c));
        adj[b].push_back(Pair(a, c));
    }

    int ans;
    int maxidx = bfs(v, 1, adj, ans);
    bfs(v, maxidx, adj, ans);
    cout << ans;
}