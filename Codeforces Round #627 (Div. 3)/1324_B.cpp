#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001] = {0};
void init()
{
    for (int i = 0; i <= 5000; i++)
        memset(dp + i, 0, sizeof(int) * 5001);
}
int solve(vector<int> &a)
{
    vector<int> b = a;
    reverse(b.begin(), b.end());
    int mlen = 0;
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[j - 1] == b[i - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            mlen = max(mlen, dp[i][j]);
            if (3 <= mlen)
                return mlen;
        }
    }
    return mlen;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        init();

        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &a : arr)
            cin >> a;
        int ans = solve(arr);
        cout << (3 <= ans ? "YES" : "NO") << '\n';
    }
}