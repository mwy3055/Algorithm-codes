#include <bits/stdc++.h>

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
    // 탑의 맨 밑에 놓을 수 있는 최대한 작은 값을 선택한다.
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