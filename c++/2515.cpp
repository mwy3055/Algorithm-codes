#include <bits/stdc++.h>

using pii = std::pair<int, int>; // height, price

int n, s;
std::vector<int> heights, costs;

// dp[i]: i번째 그림까지 봤을 때 얻을 수 있는 최대 가격
int dp[300010];

/*
i번 그림을 놓을 경우
    - i번째 그림 밑에 놓을 수 있는 그림 중 가장 높은 그림 before를 찾아야 함 (upper_bound - 1)
    - dp[i] = dp[before] + cost[i]
i번 그림을 놓지 않는 경우
    - dp[i] = dp[i-1]
*/
int solve2()
{
    int no_dup_n = heights.size();
    for (int i = 1; i <= no_dup_n; i++)
    {
        auto &h = heights[i - 1], &c = costs[i - 1];
        auto before = std::upper_bound(heights.begin(), heights.end(), h - s) - heights.begin();
        if (before < 0 || before >= no_dup_n)
            dp[i] = dp[i - 1];
        else
            dp[i] = std::max(dp[i - 1], dp[before] + c);
    }
    return dp[no_dup_n];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<pii> paints;
    std::cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        int h, c;
        std::cin >> h >> c;
        paints.emplace_back(h, c);
    }

    std::sort(paints.begin(), paints.end());
    for (auto &p : paints)
    {
        if (!heights.empty() && heights.back() == p.first)
        {
            heights.pop_back();
            costs.pop_back();
        }
        heights.push_back(p.first);
        costs.push_back(p.second);
    }

    std::cout << solve2();
}