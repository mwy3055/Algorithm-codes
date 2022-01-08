#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        std::vector<int> arr{x, y, z, std::max(std::max(x, y), z), std::max(1, std::min(std::min(x, y), z) - 1)};
        std::sort(arr.begin(), arr.end());
        bool find = false;
        do
        {
            int a = arr[0], b = arr[1], c = arr[2];
            if (std::max(a, b) == x && std::max(a, c) == y && std::max(b, c) == z)
            {
                std::cout << "YES\n"
                          << a << ' ' << b << ' ' << c << '\n';
                find = true;
                break;
            }
        } while (std::next_permutation(arr.begin(), arr.end()));
        if (!find)
            std::cout << "NO\n";
    }
}