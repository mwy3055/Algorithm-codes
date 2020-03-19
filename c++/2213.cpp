#include <bits/stdc++.h>
using namespace std;

int n, w[10001], dp[10001][2], type[10001];
vector<int> graph[10001];
bool visit[10001];

void search(int i)
{
    visit[i] = true;
    int &dp0 = dp[i][0], &dp1 = dp[i][1];
    for (auto &child : graph[i])
    {
        if (visit[child])
            continue;
        search(child);

        dp0 += dp[child][1];
        if (dp[child][0] < dp[child][1])
        {
            dp1 += dp[child][1];
            type[child] = 1;
        }
        else
        {
            dp1 += dp[child][0];
            type[child] = 0;
        }
    }
    dp0 += w[i];
}
void track(int i, int mode, set<int> &nodes)
{
    visit[i] = true;
    if (mode == 0)
    {
        nodes.insert(i);
        for (auto &child : graph[i])
        {
            if (!visit[child])
                track(child, 1, nodes);
        }
    }
    else
    {
        for (auto &child : graph[i])
        {
            if (!visit[child])
                track(child, type[child], nodes);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    search(1);
    int ans, mtype;
    if (dp[1][0] < dp[1][1])
    {
        ans = dp[1][1];
        mtype = 1;
    }
    else
    {
        ans = dp[1][0];
        mtype = 0;
    }

    for (int i = 1; i <= n; i++)
        visit[i] = false;
    set<int> nodes; // answer nodes
    track(1, mtype, nodes);
    cout << ans << '\n';
    for (auto &n : nodes)
        cout << n << ' ';
}