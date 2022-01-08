#include <bits/stdc++.h>

const int INF = -(1 << 29);
std::vector<int> nums;
int dp[51][51];

// turn: 0-현우, 1-서하
// l: 현재 남은 카드의 왼쪽 끝
// r: 현재 남은 카드의 오른쪽 끝+1. 남은 카드 장수: r-l
// 현재 turn인 플레이어가 최선을 다했을 때, 상대보다 몇 점이나 더 얻을 수 있는가?
int solve(int l, int r)
{
    auto &ret = dp[l][r];
    if (ret != INF)
        return ret;
    if (l >= r)
        return ret = 0;

    ret = nums[l] - solve(l + 1, r);
    ret = std::max(ret, nums[r - 1] - solve(l, r - 1));
    if (r - l >= 2)
    {
        ret = std::max(ret, -solve(l + 2, r));
        ret = std::max(ret, -solve(l, r - 2));
    }
    return ret;
}

void init()
{
    nums.clear();
    for (int i = 0; i <= 50; i++)
    {
        for (int j = 0; j <= 50; j++)
        {
            dp[i][j] = INF;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int c;
    std::cin >> c;
    while (c--)
    {
        init();
        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++)
        {
            int num;
            std::cin >> num;
            nums.push_back(num);
        }
        std::cout << solve(0, n) << '\n';
    }
}