#include <bits/stdc++.h>

int n, k;
std::vector<int> scores;

void getinput()
{
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int s;
        std::cin >> s;
        scores.push_back(s);
    }
}

int score_sum()
{
    int sum = 0;
    for (auto &s : scores)
        sum += s;
    return sum;
}

bool can_divide(int min)
{
    // n개의 수를 k개의 그룹으로 나눌 떄, 합의 최솟값이 min이 될 수 있는가?
    // 는 너무 어렵다. 따라서 문제를 바꾸자.
    // n개의 수를 합의 최솟값이 min인 그룹으로 나눌 때
    // k개 이상으로 나눌 수 있는가?
    int group = 0, sum = 0;
    for (auto &score : scores)
    {
        sum += score;
        if (sum >= min)
        {
            group++;
            sum = 0;
        }
    }
    return group >= k;
}

int solve()
{
    int sum = score_sum();
    int l = 0, r = sum + 1; // [l, r)
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (can_divide(mid))
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}