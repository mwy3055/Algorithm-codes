#include <bits/stdc++.h>
using namespace std;

void bfs(int &n, vector<vector<int>> &adj, int *parent)
{
    bool visit[n + 1] = {false};
    queue<int> q;

    q.push(1);
    visit[1] = true;

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        for (auto &next : adj[top])
        {
            if (!visit[next])
            {
                parent[next] = top;
                visit[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int parent[n + 1];
    vector<vector<int>> adj(n + 1, vector<int>());

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(n, adj, parent);

    for (int i = 2; i <= n; i++)
        cout << parent[i] << '\n';
}