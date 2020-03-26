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
        int n;
        cin >> n;
        string x, a, b;
        cin >> x;
        for (int i = 0; i < n; i++)
        {
            if (x[i] == '0')
            {
                a.push_back('0');
                b.push_back('0');
            }
            else if (x[i] == '1')
            {
                a.push_back('1');
                b.push_back('0');
            }
            else
            {
                a.push_back('1');
                b.push_back('1');
            }
        }
        cout << a << '\n'
             << b << '\n';
    }
}