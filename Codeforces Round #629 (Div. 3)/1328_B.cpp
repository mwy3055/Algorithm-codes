#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve(ll len, ll k, int bleft, ll &n, string &ans)
{
    if (bleft == 0)
    {
        for (int i = 0; i < len; i++)
            ans.push_back('a');
        return;
    }
    if (len == 1)
    {
        ans.push_back((bleft ? 'b' : 'a'));
        return;
    }

    ll div;
    if (bleft == 2)
        div = (len - 1) * (len - 2) / 2;
    else
        div = len - 1;
    if (k <= div)
    {
        ans.push_back('a');
        solve(len - 1, k, bleft, n, ans);
    }
    else
    {
        ans.push_back('b');
        solve(len - 1, k - div, bleft - 1, n, ans);
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
        ll n, k;
        cin >> n >> k;
        string ans;
        solve(n, k, 2, n, ans);
        cout << ans << '\n';
    }
}