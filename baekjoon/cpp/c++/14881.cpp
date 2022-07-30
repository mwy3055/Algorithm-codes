#include <bits/stdc++.h>

int GCD(int a, int b)
{
    // constraint: a <= b
    if (a > b)
    {
        std::swap(a, b);
    }
    if (b % a)
        return GCD(a, b % a);
    else
        return a;
}

bool solve(int a, int b, int c)
{
    if (std::max(a, b) < c)
        return false;
    if (a == c || b == c)
        return true;
    auto gcd = GCD(a, b);
    return c % gcd == 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        std::cout << (solve(a, b, c) ? "YES" : "NO") << '\n';
    }
}