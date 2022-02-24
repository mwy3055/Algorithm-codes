#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> order;

int solve()
{
    int n;
    cin >> n;
    vector<int> t(n), enter(n + 1, 0);
    for (auto &team : t)
        cin >> team;
    set<int> adj[n + 1]; // adj[i]: index of teams below team i
    for (int i = 0; i < n; i++)
    {
        auto &upper = t[i];
        for (int j = i + 1; j < n; j++)
        {
            auto &lower = t[j];
            adj[upper].insert(lower);
            enter[lower]++;
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (adj[a].count(b))
        {
            adj[a].erase(b);
            enter[b]--;
            adj[b].insert(a);
            enter[a]++;
        }
        else if (adj[b].count(a))
        {
            adj[b].erase(a);
            enter[a]--;
            adj[a].insert(b);
            enter[b]++;
        }
    }

    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (enter[i] == 0)
        {
            q.push(i);
        }
    }

    for (int a = 0; a < n; a++) // should visit n nodes exactly to do topology sort
    {
        if (q.empty())
        {
            return 2; // cycle: error! "IMPOSSIBLE"
        }
        if (1 < q.size())
        {
            return 1; // can't determine order "?"
        }

        auto top = q.front();
        q.pop();
        ans.push_back(top);
        for (auto &lower : adj[top])
        {
            if (--enter[lower] == 0)
            {
                q.push(lower);
            }
        }
    }

    for (auto &a : ans)
        cout << a << ' ';
    cout << '\n';
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int rtn = solve();
        if (rtn == 1)
            cout << '?' << '\n';
        else if (rtn == 2)
            cout << "IMPOSSIBLE" << '\n';
    }
}