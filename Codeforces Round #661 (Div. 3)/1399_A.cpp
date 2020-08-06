#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        bool ans = true;
        std::cin >> n;
        std::vector<int> arr(n), diff;
        for (auto &a : arr)
            std::cin >> a;
        diff = arr;
        while (true)
        {
            if (diff.size() == 1)
                break;
            std::vector<int> temp;
            int siz = diff.size();
            for (int i = 0; i < siz - 1; i++)
            {
                temp.push_back(diff[i] - diff[i + 1]);
                if (std::abs(temp.back()) > 1)
                {
                    ans = false;
                    break;
                }
            }
            if (!ans)
                break;
            diff = temp;
        }

        std::cout << (ans ? "YES" : "NO") << '\n';
    }
}