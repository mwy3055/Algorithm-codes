#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll INF = 1LL << 32;
ll cnt(ll mid, vll &a, vll &b, vll &c) // number of value less or equal than mid
{
    ll cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] <= mid)
        {
            cnt += (min(mid, c[i]) - a[i]) / b[i] + 1;
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vll a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> c[i] >> b[i];
    }

    ll l = 1, r = INF; // [l, r)
    while (l < r)
    {
        ll mid = (l + r) / 2;
        if (cnt(mid, a, b, c) % 2)
            r = mid;
        else
            l = mid + 1;
    }
    if (l >= INF)
        cout << "NOTHING";
    else
        cout << l << ' ' << cnt(l, a, b, c) - cnt(l - 1, a, b, c);
}