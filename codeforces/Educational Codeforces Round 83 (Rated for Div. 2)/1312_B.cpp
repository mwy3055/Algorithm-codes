#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
void solve(int &n, vector<int> &arr)
{
    vector<int> backup = arr;
    vector<pii> candidates[100][100];
    int diff[n][n]; // diff[i][j] = arr[j] - arr[i]
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            diff[i][j] = arr[j] - arr[i];
}
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
        vector<int> arr(n);
        for (auto &a : arr)
            cin >> a;

        solve(n, arr);
        for (auto &a : arr)
            cout << a << ' ';
        cout << '\n';
    }
}