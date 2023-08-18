#include <bits/stdc++.h>

using ll = long long;

int n;
std::vector<ll> a;

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        a.push_back(num);
    }
}

int solve()
{
    int ans1 = 0;
    ll sum1 = (a[0] + a[1]) * 3;
    for (int i = 1; i < n - 1; i++)
    {
        if ((a[i] + a[i + 1]) * 3 < sum1)
        {
            sum1 = (a[i] + a[i + 1]) * 3;
            ans1 = i;
        }
    }
    if (n == 2)
        return ans1;

    int ans2 = 0;
    ll sum2 = (a[0] + a[1] + a[2]) * 2;
    for (int i = 1; i < n - 2; i++)
    {
        if ((a[i] + a[i + 1] + a[i + 2]) * 2 < sum2)
        {
            sum2 = (a[i] + a[i + 1] + a[i + 2]) * 2;
            ans2 = i;
        }
    }

    if (sum1 < sum2)
        return ans1;
    else if (sum1 > sum2)
        return ans2;
    else
        return std::min(ans1, ans2);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}