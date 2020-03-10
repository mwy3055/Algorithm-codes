#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll num, int &k, map<ll, bool> &dp, vector<int> &lis)
{
    if (num == 0)
    {
        return dp[0] = true;
    }
    if (dp.count(num))
        return dp[num];

    int idx = (int)(log(num) / log(k) + 1);
    ll cur = 1;
    for (int i = 0; i < idx; i++)
        cur *= k;

    bool ans = false;
    while (cur)
    {
        if (cur <= num && check(num - cur, k, dp, lis))
        {
            ans = true;
            break;
        }
        cur /= k;
        idx--;
    }
    if (ans)
        lis.push_back(idx);
    return dp[num] = ans;
}

void solve(vector<ll> &arr, int &n, int &k, vector<vector<int>> &result)
{
    for (int i = 0; i < n; i++)
    {
        map<ll, bool> dp;
        check(arr[i], k, dp, result[i]);
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
        int n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for (auto &a : arr)
            cin >> a;
        vector<vector<int>> result(n, vector<int>());
        solve(arr, n, k, result);

        int slen = 0;
        set<int> s;
        for (auto &res : result)
        {
            slen += res.size();
            s.insert(res.begin(), res.end());
        }
        if (s.size() == slen)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}