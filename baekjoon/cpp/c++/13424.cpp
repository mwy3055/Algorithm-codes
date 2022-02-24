#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int solve(int &n, vector<vector<int>> &adj, vector<int> &loc)
{
    for (int i = 1; i <= n; i++)
        adj[i][i] = 0;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j && j != k && k != i)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    int mdist = INF, midx = 0;
    for (int k = 1; k <= n; k++)
    {
        int tdist = 0;
        for (auto &l : loc)
        {
            tdist += adj[l][k];
        }
        if (tdist < mdist)
        {
            mdist = tdist;
            midx = k;
        }
    }
    return midx;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, INF));
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a][b] = adj[b][a] = c;
        }
        int k;
        cin >> k;
        vector<int> loc(k);
        for (int i = 0; i < k; i++)
            cin >> loc[i];

        cout << solve(n, adj, loc) << '\n';
    }
}