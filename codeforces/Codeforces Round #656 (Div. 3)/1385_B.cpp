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
        std::cin >> n;
        std::vector<int> arr(2 * n), ans;
        std::vector<bool> visit(n + 1, false);
        for (auto &a : arr)
            std::cin >> a;

        for (int i = 0; i < 2 * n; i++)
        {
            if (visit[arr[i]])
                continue;
            auto dup = std::find(arr.begin() + i + 1, arr.end(), arr[i]);
            if (dup == arr.end())
                continue;
            for (auto it = arr.begin() + i; it != dup; it++)
            {
                if (!visit[*it])
                {
                    ans.push_back(*it);
                    visit[*it] = true;
                }
            }
        }

        for (auto &a : ans)
            std::cout << a << ' ';
        std::cout << '\n';
    }
}