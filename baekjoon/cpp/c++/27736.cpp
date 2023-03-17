#include <bits/stdc++.h>

// 2023 중앙대 A번

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    int agree = 0, oppose = 0, abstain = 0;
    int half;
    if (n % 2 == 0)
        half = n / 2;
    else
        half = n / 2 + 1;
    for (int i = 0; i < n; i++)
    {
        int vote;
        std::cin >> vote;
        if (vote == 1)
            agree++;
        else if (vote == -1)
            oppose++;
        else if (vote == 0)
            abstain++;
        else
            exit(-1);
    }

    if ((n > 1 && abstain >= half) || abstain == n)
        std::cout << "INVALID" << '\n';
    else if (agree > oppose)
        std::cout << "APPROVED" << '\n';
    else
        std::cout << "REJECTED" << '\n';
}