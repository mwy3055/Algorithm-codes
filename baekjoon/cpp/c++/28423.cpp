#include <bits/stdc++.h>

int l, r;
int dp[100001];

const int NOT_CALCULATED = -3, CALCULATING = -2;

void getinput()
{
    std::cin >> l >> r;
}

int mtp(int n)
{
    int result = 1;
    do
    {
        result *= n % 10;
        n /= 10;
    } while (n);
    return result;
}

int sum(int n)
{
    int result = 0;
    while (n)
    {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int f(int n)
{
    auto n1 = sum(n), n2 = mtp(n);
    std::stringstream ss;
    ss << n1 << n2;
    return std::stoi(ss.str());
}

int search(int n)
{
    if (n > 100000)
        return -1;

    auto &ret = dp[n];
    if (ret != NOT_CALCULATED)
        return ret;

    if (n == f(n))
        return ret = 1;
    ret = 0;
    return ret = search(f(n));
}

int solve()
{
    for (int i = 0; i <= 100000; i++)
        dp[i] = NOT_CALCULATED;

    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        ans += search(i);
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}