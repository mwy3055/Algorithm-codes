#include <bits/stdc++.h>

using vi = std::vector<int>;
vi friends[501];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    bool invite[501] = {false};
    for (auto &f : friends[1])
    {
        invite[f] = true;
        for (auto &ff : friends[f])
        {
            invite[ff] = true;
        }
    }

    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (invite[i])
        {
            ans++;
        }
    }
    std::cout << ans;
}