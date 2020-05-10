#include <bits/stdc++.h>
using namespace std;

int getsubsum(vector<int> &tsum, int l, int r)
{
    return tsum[r] - (l ? tsum[l - 1] : 0);
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
        vector<int> arr(n), tsum(n, 0), valcount(n + 1, 0);
        vector<bool> used(n + 1, false);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            tsum[i] = arr[i] + (i ? tsum[i - 1] : 0);
            valcount[arr[i]]++;
        }
        int ans = 0;
        for (int l = 0; l < n; l++)
        {
            for (int r = l + 1; r < n; r++)
            {
                int subsum = getsubsum(tsum, l, r);
                if (subsum <= n && !used[subsum])
                {
                    ans += valcount[subsum];
                    used[subsum] = true;
                }
            }
        }
        cout << ans << '\n';
    }
}
//4 5 9 6 5