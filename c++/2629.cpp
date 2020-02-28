#include <bits/stdc++.h>
using namespace std;

int n, m, weight[30];
bool dp[15001], temp[15001];

bool isin(int a)
{
    return 0 <= a && a <= 15000;
}
void solve()
{
    dp[weight[0]] = true;
    for (int i = 1; i < n; i++)
    {
        int &cur = weight[i];
        temp[cur] = true;
        for (int j = 0; j <= 15000; j++)
        {
            if (dp[j])
                temp[j] = true;
            if (isin(j - cur) && dp[j - cur])
                temp[j] = true;
            if (isin(j + cur) && dp[j + cur])
                temp[j] = true;
            if (isin(cur - j) && dp[cur - j])
                temp[j] = true;
        }
        memcpy(dp, temp, sizeof(bool) * 15001);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    solve();

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int w;
        cin >> w;
        if (w <= 15000 && dp[w])
            cout << 'Y' << ' ';
        else
            cout << 'N' << ' ';
    }
}