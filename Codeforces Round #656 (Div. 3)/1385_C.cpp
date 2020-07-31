#include <bits/stdc++.h>

bool isbitonic(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    bool transit = false;
    for (auto it = begin; it != end - 1; it++)
    {
        if (*it == *(it + 1))
            continue;
        if (!transit && *it < *(it + 1))
        {
            continue;
        }
        else if (!transit && *it > *(it + 1))
        {
            transit = true;
            continue;
        }
        else if (transit && *it > *(it + 1))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
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
        std::vector<int> arr(n);
        for (auto &a : arr)
            std::cin >> a;
        int ans = 0;
        bool transit = false;
        for (int i = n - 1; i > 0; i--)
        {
            if (arr[i - 1] == arr[i])
                continue;
            else if (!transit && arr[i - 1] > arr[i])
                continue;
            else if (!transit && arr[i - 1] < arr[i])
                transit = true;
            else if (transit && arr[i - 1] < arr[i])
                continue;
            else
            {
                ans = i;
                break;
            }
        }
        std::cout << ans << '\n';
    }
}