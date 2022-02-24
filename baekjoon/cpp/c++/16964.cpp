#include <bits/stdc++.h>
using namespace std;

bool visit[100001] = {false};

void dfs(int node, vector<set<int>> &adj, vector<set<int>> &diradj)
{
    visit[node] = true;
    for (auto &y : adj[node])
    {
        if (!visit[y])
        {
            diradj[node].insert(y);
            dfs(y, adj, diradj);
        }
    }
}

bool solve(int node, vector<set<int>> &adj, vector<int> &ans, int &ansidx)
{
    bool rtn = true;
    for (int i = 0; i < adj[node].size(); i++)
    {
        int y = ans[++ansidx];
        if (adj[node].find(y) == adj[node].end())
        {
            rtn = false;
            break;
        }
        rtn |= solve(y, adj, ans, ansidx);
    }
    return rtn;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<set<int>> adj(n + 1, set<int>()), diradj(n + 1, set<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        ans.push_back(c);
    }
    if (ans[0] != 1)
    {
        cout << 0;
        return 0;
    }
    dfs(1, adj, diradj);

    int idx = 0;
    cout << solve(1, diradj, ans, idx);
}