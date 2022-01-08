#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll a, ll b)
{
    //constraint: a <= b
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b % a)
        return GCD(a, b % a);
    else
        return a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        bool find = false;
        int x;
        cin >> x;
        cout << 1 << ' ' << x - 1 << '\n';
    }
}