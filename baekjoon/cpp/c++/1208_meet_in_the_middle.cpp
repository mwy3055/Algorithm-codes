#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int arr[40], n, s, subsum[4000001];
ll ans;
//https://hrothgar.tistory.com/49
void dfs_front(int i, ll sum, bool nullset)
{
    if (i == n / 2)
    {
        if (!nullset)
            return;
        if (sum == s)
            ans++;
        subsum[sum + 2000000]++;

        return;
    }

    dfs_front(i + 1, sum + arr[i], nullset | true);
    dfs_front(i + 1, sum, nullset);
}
void dfs_back(int i, ll sum, bool nullset)
{
    if (i == n)
    {
        if (!nullset)
            return;
        if (sum == s)
            ans++;
        if (-2000000 <= s - sum && s - sum <= 2000000)
            ans += subsum[s - sum + 2000000];

        return;
    }

    dfs_back(i + 1, sum + arr[i], nullset | true);
    dfs_back(i + 1, sum, nullset);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dfs_front(0, 0, false);
    dfs_back(n / 2, 0, false);

    cout << ans;
}