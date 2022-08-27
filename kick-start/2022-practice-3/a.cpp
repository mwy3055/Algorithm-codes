#include <bits/stdc++.h>

int n, m;
std::vector<int> candies;

void getinput()
{
    candies.clear();
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int candy;
        std::cin >> candy;
        candies.push_back(candy);
    }
}

int solve()
{
    int sum = 0;
    for (auto &c : candies)
        sum += c;
    return sum % m;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++)
    {
        getinput();
        int answer = solve();
        std::cout << "Case #" << i << ": " << answer << '\n';
    }
}