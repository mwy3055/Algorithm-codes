#include <bits/stdc++.h>

int n, k;
std::vector<int> numbers;

bool dp[50001][51];

void getinput()
{
    std::cin >> n;
    numbers.resize(n);
    for (int i = 0; i < n; i++)
        std::cin >> numbers[i];
    std::cin >> k;
}

void solve()
{
    std::sort(numbers.begin(), numbers.end());

    // dp
    for (auto &num : numbers)
    {
        dp[num][1] = true;
    }
    for (int i = 1; i <= 50000; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            for (auto &num : numbers)
            {
                if (i - num >= 0 && dp[i - num][j - 1])
                {
                    dp[i][j] = true;
                }
            }
        }
    }

    int num = -1;
    for (int i = 1; i <= 50000; i++)
    {
        bool can = false;
        for (int j = 1; j <= k; j++)
        {
            if (dp[i][j] == true)
            {
                can = true;
                break;
            }
        }
        if (!can)
        {
            num = i;
            break;
        }
    }

    if (num % 2)
        std::cout << "jjaksoon win at " << num << '\n';
    else
        std::cout << "holsoon win at " << num << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}