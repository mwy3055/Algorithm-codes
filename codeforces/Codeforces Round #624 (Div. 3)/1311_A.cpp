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
        if (a < b)
        {
            cout << (((a & 1) == (b & 1)) ? 2 : 1) << '\n';
        }
        else if (a > b)
        {
            cout << (((a & 1) != (b & 1)) ? 2 : 1) << '\n';
        }
        else
            cout << 0 << '\n';
    }
}