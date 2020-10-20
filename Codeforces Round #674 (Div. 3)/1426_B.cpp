#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int n, m;
        std::cin >> n >> m;
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            int a, b, c, d;
            std::cin >> a >> b >> c >> d;
            if (b == c)
                ans = true;
        }
        if (m % 2)
            std::cout << "NO" << '\n';
        else
            std::cout << (ans ? "YES" : "NO") << '\n';
    }
}