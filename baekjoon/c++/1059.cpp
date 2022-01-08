#include <bits/stdc++.h>
using namespace std;

void test(int &n, int left, int right) //[left+1, right-1]에서 찾아야 함
{
    int ans = 0;
    for (int i = left + 1; i <= n; i++)
    {
        for (int j = max(i + 1, n); j < right; j++)
        {
            ans++;
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l;
    cin >> l;
    vector<int> v(l);
    for (int i = 0; i < l; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    int n;
    cin >> n;

    int left = distance(v.begin(), upper_bound(v.begin(), v.end(), n));
    int right = distance(v.begin(), lower_bound(v.begin(), v.end(), n));

    if (v[left] == n || v[right] == n)
    {
        cout << 0;
        return 0;
    }

    if (0 < left)
        left--;

    test(n, (n < v[left] ? 0 : v[left]), v[right]);
}