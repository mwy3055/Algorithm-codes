#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> graph[1001];
vector<int> ans, enter(1001, 0);

bool solve()
{
    // do topology sort
    int left = n;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (enter[i] == 0)
        {
            q.push(i);
            left--;
        }
    }
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        ans.push_back(top);
        for (auto &adj : graph[top])
        {
            if (--enter[adj] == 0)
            {
                q.push(adj);
                left--;
            }
        }
    }
    return left == 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int p;
        cin >> p;
        vector<int> order(p);
        for (auto &o : order)
            cin >> o;
        for (int j = 0; j < p - 1; j++)
        {
            if (graph[order[j]].find(order[j + 1]) == graph[order[j]].end())
            {
                graph[order[j]].insert(order[j + 1]);
                enter[order[j + 1]]++;
            }
        }
    }

    if (solve())
        for (auto &a : ans)
            cout << a << '\n';
    else
        cout << 0;
}