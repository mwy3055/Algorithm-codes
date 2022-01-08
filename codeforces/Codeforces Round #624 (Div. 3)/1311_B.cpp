#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // number, index

bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<pii> a(n);
    bool forward[n + 1] = {false}, backward[n + 1] = {false};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        forward[t - 1] = backward[t] = true;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        int org = a[i].second, cur = i;
        if (org < cur)
        {
            while (org != cur)
            {
                if (forward[org])
                    org++;
                else
                    return false;
            }
        }
        else
        {
            while (org != cur)
            {
                if (backward[org])
                    org--;
                else
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}