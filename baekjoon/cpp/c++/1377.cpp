#include <bits/stdc++.h>

using pii = std::pair<int, int>; // value, index

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<pii> inputs;
    for (int i = 0; i < n; i++)
    {
        int value;
        std::cin >> value;
        inputs.emplace_back(value, i);
    }
    std::sort(inputs.begin(), inputs.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto &index = inputs[i].second;
        if (ans < index - i)
        {
            ans = index - i;
        }
    }
    std::cout << ans + 1 << '\n';
}