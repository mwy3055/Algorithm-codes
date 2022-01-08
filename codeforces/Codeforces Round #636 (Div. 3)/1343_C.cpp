#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll solve(vector<int> &arr, int &n)
{
    ll idx = 0, ans = 0;
    while (idx < n)
    {
        ll cidx = idx, tempmax = arr[idx];
        while (cidx < n && ((ll)arr[idx] * arr[cidx]) > 0)
        {
            tempmax = max(tempmax, (ll)arr[cidx]);
            cidx++;
        }
        ans += tempmax;
        idx = cidx;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &a : arr)
            cin >> a;
        cout << solve(arr, n) << '\n';
    }
}