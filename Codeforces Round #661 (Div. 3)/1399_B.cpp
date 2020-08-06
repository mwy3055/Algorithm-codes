#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int n, mina = 0x7f7f7f7f, minb = 0x7f7f7f7f;
        std::cin >> n;
        std::vector<int> numa(n), numb(n);
        for (auto &a : numa)
        {
            std::cin >> a;
            mina = std::min(mina, a);
        }
        for (auto &b : numb)
        {
            std::cin >> b;
            minb = std::min(minb, b);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int diffa = numa[i] - mina, diffb = numb[i] - minb;
            ans += std::max(diffa, diffb);
            // if (diffa == diffb)
            // {
            //     ans += diffa;
            // }
            // else
            // {
            //     int minv = std::min(diffa, diffb), maxv = std::max(diffa, diffb);
            //     ans += maxv;
            // }
        }
        std::cout << ans << '\n';
    }
}