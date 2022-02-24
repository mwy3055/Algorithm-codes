#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans = 0, a, b;
void dfs(ll n)
{
    if (b < n)
        return;
    if (a <= n && n <= b)
        ans++;
    dfs(n * 10 + 4);
    dfs(n * 10 + 7);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;

    dfs(4);
    dfs(7);
    cout << ans;
}