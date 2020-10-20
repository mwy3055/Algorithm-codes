#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int n, x;
        std::cin >> n >> x;
        if (n <= 2)
            std::cout << 1 << '\n';
        else
        {
            std::cout << (n - 3) / x + 2 << '\n';
        }
    }
}