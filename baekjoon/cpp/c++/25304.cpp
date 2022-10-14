#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int x, n;
    std::cin >> x >> n;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        sum += a * b;
    }
    std::cout << (x == sum ? "Yes" : "No") << '\n';
}