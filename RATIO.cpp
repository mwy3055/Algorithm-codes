#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 2000000000;
double winratio(int game, int win)
{
    return (ll)win * 100 / game;
}
bool ratio_increases(int n, int m, ll game)
{
    int z = winratio(n, m), newz = winratio(n + game, m + game);
    return z < newz;
}
int solve(int n, int m)
{
    if (99 <= winratio(n, m))
        return MAX + 1;

    ll l = 1, r = 2000000000;
    while (l < r)
    {
        ll mid = (l + r) / 2;
        if (ratio_increases(n, m, mid))
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int ans = solve(n, m);
        if (MAX < ans)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
}