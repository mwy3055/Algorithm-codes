#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
        ll nth = (k - 1) / (n - 1);
        ll remainder = (k - 1) % (n - 1) + 1;
        cout << n * nth + remainder << '\n';
    }
}