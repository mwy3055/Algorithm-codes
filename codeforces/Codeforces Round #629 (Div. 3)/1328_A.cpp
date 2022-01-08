#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int mod = a % b;
        if (mod)
            cout << b - mod << '\n';
        else
            cout << 0 << '\n';
    }
}