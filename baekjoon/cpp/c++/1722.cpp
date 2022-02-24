#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
ll fac[21];
int n, arr[20];

void init()
{
    fac[0] = 1;
    for (int i = 1; i <= 20; i++)
        fac[i] = fac[i - 1] * i;
}

void solve1(int len, ll k, vi &left, vi &ans)
{
    if (len == 2)
    {
        if (k == 1)
        {
            ans.push_back(left[0]);
            ans.push_back(left[1]);
        }
        else
        {
            ans.push_back(left[1]);
            ans.push_back(left[0]);
        }
        return;
    }
    else if (len == 1)
    {
        ans.push_back(left[0]);
        return;
    }
    if (len == 0)
        return;

    int cur = 1;
    while (cur * fac[len - 1] <= k)
    {
        cur++;
        if (cur * fac[len - 1] == k)
            break;
    }
    ans.push_back(left[cur - 1]);
    left.erase(left.begin() + cur - 1);
    solve1(len - 1, k - (cur - 1) * fac[len - 1], left, ans);
}
ll solve2(int len, vi &left, vi &arr)
{
    if (len == n)
        return 1;

    auto it = find(left.begin(), left.end(), arr[len - 1]);
    ll nth = it - left.begin() + 1;
    left.erase(it);
    return (nth - 1) * fac[n - len] + solve2(len + 1, left, arr);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    cin >> n;
    int type;
    cin >> type;
    vi left;
    for (int i = 1; i <= n; i++)
        left.push_back(i);
    if (type == 1)
    {
        ll k;
        vi ans;
        cin >> k;
        solve1(n, k, left, ans);
        for (auto &a : ans)
            cout << a << ' ';
    }
    else
    {
        vi arr(n);
        for (auto &a : arr)
            cin >> a;
        cout << solve2(1, left, arr);
    }
}