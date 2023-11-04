#include <bits/stdc++.h>

int GCD(int a, int b)
{
    // constraint: a <= b
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b % a)
        return GCD(a, b % a);
    else
        return a;
}

int solve(int n, int m)
{
    if (n % m == 0)
    {
        return 0;
    }
    else
    {
        auto gcd = GCD(n, m);
        return m - gcd;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::cout << solve(n, m) << '\n';
}