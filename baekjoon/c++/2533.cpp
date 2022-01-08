#include <bits/stdc++.h>
using namespace std;

int n, dp[1000001][2];
vector<int> graph[1000001], child[1000001];
bool visit[1000001];

void makechild(int cur)
{
    visit[cur] = true;
    for (auto &adj : graph[cur])
    {
        if (!visit[adj])
        {
            child[cur].push_back(adj);
            makechild(adj);
        }
    }
}
int solve(int cur, int state)
{
    int &ret = dp[cur][state];
    if (ret)
        return ret;

    if (state)
    {
        int ans = 0;
        for (auto &ch : child[cur])
            ans += min(solve(ch, 0), solve(ch, 1));
        return ret = ans + 1;
    }
    else
    {
        int ans = 0;
        for (auto &ch : child[cur])
            ans += solve(ch, 1);
        return ret = ans;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    makechild(1);

    solve(1, 0);
    solve(1, 1);
    cout << min(dp[1][0], dp[1][1]);
}