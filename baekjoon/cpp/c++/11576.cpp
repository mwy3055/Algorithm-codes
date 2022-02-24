#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getmtp(ll &a, ll m)
{
    int mtp = 1;
    while (--m)
        mtp *= a;
    return mtp;
}

void convert(ll n, int b)
{
    stack<int> s;

    while (n)
    {
        s.push(n % b);
        n /= b;
    }
    if (n)
        s.push(n);

    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
}

int main()
{
    ll a, b, m, num = 0;
    cin >> a >> b >> m;

    ll mtp = getmtp(a, m);
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        num += mtp * t;
        mtp /= a;
    }

    convert(num, b);
}