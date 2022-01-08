#include <bits/stdc++.h>
using namespace std;

int enter[32001];
bool solved[32001];
vector<int> adj[32001];

void solve(int &n)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++)
    {
        if (enter[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        while (!q.empty())
        {
            int top = q.top();
            q.pop();

            solved[top] = true;
            cout << top << ' ';
            for (auto &node : adj[top])
            {
                if (--enter[node] == 0 && !solved[node])
                    q.push(node);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        enter[b]++;
    }

    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    solve(n);
}