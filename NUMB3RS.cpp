#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

void solve(int &n, int &d, int &p, vvi &graph, vvd &dp)
{
    for (auto &adj : graph[p])
        dp[1][adj] = (1.0 / graph[p].size());
    for (int day = 2; day <= d; day++)
    {
        for (int node = 0; node < n; node++)
        {
            for (auto &adj : graph[node])
                dp[day][adj] += dp[day - 1][node] / graph[node].size();
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    while (c--)
    {
        int n, d, p;
        cin >> n >> d >> p;
        vvi graph(n, vector<int>());
        vvd dp(d + 1, vector<double>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int t;
                cin >> t;
                if (t)
                    graph[i].push_back(j);
            }
        }
        solve(n, d, p, graph, dp);

        int t;
        cin >> t;
        cout.precision(9);
        while (t--)
        {
            int query;
            cin >> query;
            cout << fixed << dp[d][query] << ' ';
        }
        cout << '\n';
    }
}