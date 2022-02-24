#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    long long n;
    std::cin >> n;
    if (n % 7 == 0 || n % 7 == 2)
        std::cout << "CY" << '\n';
    else
        std::cout << "SK" << '\n';
}