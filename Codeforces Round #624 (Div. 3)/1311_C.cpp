#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &ans)
{
    int n, m;
    cin >> n >> m;
    string s;
    vector<int> p(m);
    cin >> s;
    for (auto &pi : p)
        cin >> pi;

    vector<vector<int>> dp(n, vector<int>(26, 0));
    dp[0][s[0] - 'a']++;
    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1];
        dp[i][s[i] - 'a']++;
    }

    int ncount = 1;
    for (auto &pi : p)
    {
        if (pi == n)
            ncount++;
        else
            for (int i = 0; i < 26; i++)
            {
                ans[i] += dp[pi - 1][i];
            }
    }

    for (auto &c : s)
        ans[c - 'a'] += ncount;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        vector<int> ans(26, 0);
        solve(ans);
        for (auto &a : ans)
            cout << a << ' ';
        cout << '\n';
    }
}