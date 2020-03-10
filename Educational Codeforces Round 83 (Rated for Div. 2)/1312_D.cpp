#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int solve(int s, int e, int lval, int mval) // [s, e]
{
    if (lval > mval)
        return 0;
    if (s == e)
        return 1;
    int mid = (s + e) / 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    cout << solve(0, n - 1, 1, m) % MOD;
}