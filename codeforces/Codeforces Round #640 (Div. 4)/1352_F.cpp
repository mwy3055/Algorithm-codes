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
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        for (int i = 0; i < a; i++)
        {
            if (s.empty())
                s.append("00");
            else
                s.append("0");
        }
        for (int i = 0; i < b; i++)
        {
            if (s.empty())
                s.append(b % 2 ? "01" : "10");
            else if (s.back() == '0')
                s.append("1");
            else if (s.back() == '1')
                s.append("0");
        }
        for (int i = 0; i < c; i++)
        {
            if (s.empty() || s.back() == '0')
                s.append("11");
            else
                s.append("1");
        }
        cout << s << '\n';
    }
}