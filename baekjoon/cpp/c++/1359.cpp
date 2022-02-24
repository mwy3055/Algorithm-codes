#include <bits/stdc++.h>
using namespace std;

int comb[9][9];

int combination(int n, int k)
{
    auto &ret = comb[n][k];
    if (ret)
        return ret;
    else if (n == k || k == 0)
        return ret = 1;
    return ret = combination(n - 1, k) + combination(n - 1, k - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    for (int i = k; i <= m; i++)
    {
        if (m - i <= n - m)
            ans += combination(m, i) * combination(n - m, m - i);
    }
    cout.precision(10);
    cout << (double)ans / combination(n, m);
}