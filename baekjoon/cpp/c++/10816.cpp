#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int query;
        cin >> query;
        cout << upper_bound(arr, arr + n, query) - lower_bound(arr, arr + n, query) << ' '; //°Å¸®
    }
}