#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll>::iterator vlit;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> v(n), ans(3);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    ll sum = 1LL << 60;
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = n - 1;
        while (l < r)
        {
            if (l != i && r != i && abs(v[l] + v[r] + v[i]) < abs(sum))
            {
                ans[0] = v[l], ans[1] = v[r], ans[2] = v[i];
                sum = ans[0] + ans[1] + ans[2];
            }

            if (abs(v[l] + v[r - 1] + v[i]) <= abs(v[l + 1] + v[r] + v[i]))
                r--;
            else
                l++;
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
}