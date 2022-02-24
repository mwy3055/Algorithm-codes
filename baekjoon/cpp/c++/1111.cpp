#include <bits/stdc++.h>

int n;
std::vector<int> numbers;

void solve()
{
    if (n == 1)
    {
        std::cout << "A" << '\n';
        return;
    }
    else if (n == 2)
    {
        if (numbers[0] == numbers[1])
        {
            std::cout << numbers[0] << '\n';
        }
        else
        {
            std::cout << "A" << '\n';
        }
        return;
    }
    // n > 2
    // 처음 세 개의 수를 이용해 y = ax + b를 결정하고,
    // 모든 수에 대해 식이 성립하는지 확인한다.
    int a, b;
    int d1 = numbers[1] - numbers[0];
    int d2 = numbers[2] - numbers[1];
    if (d1 != 0)
        a = d2 / d1;
    else
        a = 0;
    b = numbers[1] - a * numbers[0];
    bool exists = true;
    for (int i = 1; i < n; i++)
    {
        if (a * numbers[i - 1] + b != numbers[i])
        {
            exists = false;
            break;
        }
    }
    if (exists)
        std::cout << a * numbers[n - 1] + b << '\n';
    else
        std::cout << "B" << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }

    solve();
}