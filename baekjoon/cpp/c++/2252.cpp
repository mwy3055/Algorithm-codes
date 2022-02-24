#include <bits/stdc++.h>
using namespace std;

void getinput(int &n, int &m, int *enter, vector<vector<int>> &adj)
{
    for (int i = 0; i < n; i++)
        enter[i] = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        enter[b - 1]++;
        adj[a - 1].push_back(b - 1);
    }
}
void top_sort(int &n, int &m, int *enter, vector<vector<int>> &adj)
{
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (enter[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int &top = q.front();
        q.pop();
        cout << top + 1 << " ";

        for (int &t : adj[top])
            if (--enter[t] == 0)
                q.push(t);
        adj[top].clear();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int *enter = new int[n];
    vector<vector<int>> adj(n);
    getinput(n, m, enter, adj);

    top_sort(n, m, enter, adj);
}