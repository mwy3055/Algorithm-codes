#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    long long n;
    std::cin >> n;
    if (n % 5 == 0 || n % 5 == 2)
        std::cout << "CY" << '\n';
    else
        std::cout << "SK" << '\n';
}