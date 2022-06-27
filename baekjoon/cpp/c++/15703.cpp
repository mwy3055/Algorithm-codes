#include <bits/stdc++.h>

using pii = std::pair<int, int>;

int n;
std::vector<int> arr, track(1000);

void getinput()
{
    std::cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
}

void select()
{
    std::vector<int> values;

    values.emplace_back(0);
    int idx = 1;
    while (idx < arr.size())
    {
        int height = values.size();
        if (arr[idx] >= height)
        {
            values.emplace_back(idx);
        }
        idx++;
    }

    for (auto it = values.rbegin(); it != values.rend(); it++)
    {
        arr.erase(arr.begin() + (*it));
    }
}

int solve()
{
    std::sort(arr.begin(), arr.begin() + n);
    int ans = 0;
    while (!arr.empty())
    {
        select();
        ans++;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}