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
        vector<int> odd, even;
        for (int i = 0; i < n; i++)
        {
            int p;
            cin >> p;
            if (p % 2)
                odd.push_back(i + 1);
            else
                even.push_back(i + 1);
        }
        if (odd.size() <= 1 && even.size() == 0)
            cout << -1 << '\n';
        else
        {
            if (even.size())
            {
                cout << 1 << '\n'
                     << even[0] << '\n';
            }
            else
            {
                cout << 2 << '\n'
                     << odd[0] << ' ' << odd[1] << '\n';
            }
        }
    }
}