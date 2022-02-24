#include <bits/stdc++.h>

int solve(int n, int k)
{
    int ans;
    int l = 1, r = k;
    while (l <= r)
    {
        int mid = (l + r) / 2, cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += std::min(mid / i, n);
        if (cnt < k)
            l = mid + 1;
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;
    std::cout << solve(n, k);
}