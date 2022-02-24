#include <bits/stdc++.h>
using namespace std;

int n, cnt[10001], dp[10001][2];
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
        dp1 += max(dp[child][0], dp[child][1]);
    }
    dp0 += cnt[i];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> cnt[i];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    search(1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
}