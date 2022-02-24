#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n), psum(n, 0);
    for (auto &a : arr)
        cin >> a;

    psum[0] = arr[0];
    for (int i = 1; i < n; i++)
        psum[i] = psum[i - 1] + arr[i];

    int ans = -1e9;
    for (int i = 0; i + k - 1 < n; i++)
        ans = max(ans, psum[i + k - 1] - (i == 0 ? 0 : psum[i - 1]));
    cout << ans;
}