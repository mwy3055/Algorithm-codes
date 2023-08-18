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
        multimap<int, int> m;
        int k;
        cin >> k;
        while (k--)
        {
            char c;
            int n;
            cin >> c >> n;
            if (c == 'I')
            {
                m.insert({n, n});
            }
            else if (m.size() == 0) // D when siz == 0
                continue;
            else if (n == 1) // D 1: delete max
            {
                m.erase(--m.end());
            }
            else if (n == -1) // D -1: delete min
            {
                m.erase(m.begin());
            }
        }
        if (m.size())
            cout << m.rbegin()->first << ' ' << m.begin()->first << '\n';
        else
            cout << "EMPTY" << '\n';
    }
}