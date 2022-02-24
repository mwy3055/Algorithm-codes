#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> s(n + 1, 0);
    s[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        s[i] = s[i - 1] + t;
    }

    for (int a = 0; a < m; a++)
    {
        int t;
        cin >> t;
        cout << upper_bound(s.begin() + 1, s.end(), t) - s.begin() - 1 << '\n';
    }
}