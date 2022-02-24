#include <bits/stdc++.h>
using namespace std;

int n, arr[100000];

int solve()
{
    int len = 1;
    vector<int> d;

    d.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        int j = lower_bound(d.begin(), d.end(), arr[i]) - d.begin();
        if (j == len)
        {
            d.push_back(arr[i]);
            len++;
        }
        else
        {
            d[j] = arr[i];
        }
    }
    return len;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int len = solve();
        cout << len << '\n';
    }
}