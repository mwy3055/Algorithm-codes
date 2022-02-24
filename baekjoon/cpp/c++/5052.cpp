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
        vector<string> p;
        bool consistent = true;

        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string phone;
            cin >> phone;
            p.push_back(phone);
        }

        sort(p.begin(), p.end());
        for (int i = 0; i < n && consistent; i++)
        {
            for (int j = 0; j < p[i].length() - 1; j++)
            {
                if (binary_search(p.begin(), p.end(), p[i].substr(0, j + 1)))
                {
                    consistent = false;
                    break;
                }
            }
        }

        cout << (consistent ? "YES" : "NO") << '\n';
    }
}