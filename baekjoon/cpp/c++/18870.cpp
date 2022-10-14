#include <bits/stdc++.h>

int n;
std::vector<int> numbers;

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }
}

void solve()
{
    std::vector<int> temp;
    for (auto &number : numbers)
        temp.push_back(number);
    std::sort(temp.begin(), temp.end());
    temp.erase(std::unique(temp.begin(), temp.end()), temp.end());

    for (auto &number : numbers)
    {
        auto it = std::lower_bound(temp.begin(), temp.end(), number);
        std::cout << it - temp.begin() << ' ';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}