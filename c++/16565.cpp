#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;
int dp[53][53];

int combination(int n, int k)
{
    int &ret = dp[n][k];
    if (n == k || k == 0)
        return ret = 1;
    if (ret)
        return ret;
    return ret = (combination(n - 1, k) + combination(n - 1, k - 1)) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 0, coef = 1;
    for (int i = 1; i <= n / 4; i++)
    {
        ans += (coef * combination(13, i) * combination(52 - i * 4, n - i * 4));
        while (ans < 0)
            ans += MOD;
        ans %= MOD;
        coef *= -1;
    }
    cout << ans;
}