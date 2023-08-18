#include <bits/stdc++.h>
using namespace std;

int n, t[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i];

    sort(t, t + n, greater<int>());
    int mtime = 1;
    for (int i = 0; i < n; i++)
    {
        mtime = max(mtime, (i + 1) + 1 + t[i]);
    }
    cout << mtime;
}