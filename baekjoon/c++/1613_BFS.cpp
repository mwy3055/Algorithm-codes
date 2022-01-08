#include <bits/stdc++.h>
using namespace std;

bool d[501][501];

void bfs(int start, vector<vector<int>> &adj)
{
    queue<int> q;
    bool visit[501] = {false};

    q.push(start);
    visit[start] = true;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        d[start][top] = true;

        for (auto &node : adj[top])
        {
            if (!visit[node])
            {
                q.push(node);
                visit[node] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        bfs(i, adj);
    }

    int s;
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        int a, b, ans;
        cin >> a >> b;
        if (d[a][b])
            ans = -1;
        else if (d[b][a])
            ans = 1;
        else
            ans = 0;
        cout << ans << '\n';
    }
}