#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;
int dp[101][11], ssum[101], sqsum[101];
int getmin(int s, int e, vector<int> &arr)
{
    int sum, mean, sq, len = e - s + 1;
    if (s == 0)
    {
        sum = ssum[e];
        sq = sqsum[e];
    }
    else
    {
        sum = ssum[e] - ssum[s - 1];
        sq = sqsum[e] - sqsum[s - 1];
    }
    mean = (int)((double)sum / len + 0.5);
    return sq - 2 * mean * sum + mean * mean * len;
}
int solve(int cur, int &n, int s, vector<int> &arr)
{
    if (cur >= n)
        return 0;
    int &ret = dp[cur][s];
    if (s == 1)
        return ret = getmin(cur, n - 1, arr);
    if (ret != -1)
        return ret;
    ret = INF;
    for (int i = cur; i < n; i++)
    {
        ret = min(ret, solve(i + 1, n, s - 1, arr) + getmin(cur, i, arr));
    }
    return ret;
}
void init()
{
    for (int i = 0; i < 101; i++)
        memset(dp + i, -1, sizeof(int) * 11);
}
void preprocess(int &n, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    ssum[0] = arr[0];
    sqsum[0] = arr[0] * arr[0];
    for (int i = 1; i < n; i++)
    {
        ssum[i] = ssum[i - 1] + arr[i];
        sqsum[i] = sqsum[i - 1] + arr[i] * arr[i];
    }
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
        int n, s;
        cin >> n >> s;
        vector<int> arr(n);
        for (auto &a : arr)
            cin >> a;
        preprocess(n, arr);
        cout << solve(0, n, s, arr) << '\n';
    }
}