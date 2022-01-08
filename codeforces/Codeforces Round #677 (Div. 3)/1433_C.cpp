#include <bits/stdc++.h>

bool onlyone(std::vector<int> &sizes)
{
    for (auto &s : sizes)
    {
        if (s != sizes.front())
            return false;
    }
    return true;
}

int getmax(std::vector<int> &v)
{
    int rtn = -1;
    for (auto &value : v)
        rtn = std::max(rtn, value);
    return rtn;
}

bool caneat(std::vector<int> &sizes, int i)
{
    bool result = false;
    if (i > 0)
    {
        result |= sizes[i] > sizes[i - 1];
    }
    if (i < sizes.size())
    {
        result |= sizes[i] > sizes[i + 1];
    }
    return result;
}

int solve(int &n, std::vector<int> &sizes)
{
    if (onlyone(sizes))
        return -1;
    auto backup = sizes;
    std::sort(backup.begin(), backup.end());
    backup.erase(std::unique(backup.begin(), backup.end()), backup.end());
    int rtn;
    for (int i = 0; i < n; i++)
    {
        if (sizes[i] == backup.back() && caneat(sizes, i))
        {
            rtn = i + 1;
            break;
        }
    }
    return rtn;
}

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
        std::vector<int> sizes(n);
        for (int i = 0; i < n; i++)
            std::cin >> sizes[i];
        std::cout << solve(n, sizes) << '\n';
    }
}