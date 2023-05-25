#include <bits/stdc++.h>

const int MOD = 10000;
int n, k;

int dp[101][4][3];
int selected[101];

void getinput()
{
    std::cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        std::cin >> a >> b;
        selected[a] = b;
    }
}

// 오늘은 day이고, 어제 prev를 먹었다. 어제까지 연속해서 먹은 횟수는 streak.
int solve(int day, int prev, int streak)
{
    if (streak == 3)
        return 0;
    if (day > n)
        return 1;
    auto &ret = dp[day][prev][streak];
    if (ret != -1)
        return ret;

    ret = 0;
    if (selected[day])
    {
        if (prev == selected[day] && streak == 2)
            return ret = 0;
        auto next_streak = (prev == selected[day] ? streak + 1 : 1);
        return ret = solve(day + 1, selected[day], next_streak);
    }
    else
    {
        for (int i = 1; i <= 3; i++)
        {
            // day에 i번 파스타를 먹음
            auto next_streak = (prev == i ? streak + 1 : 1);
            ret = (ret + solve(day + 1, i, next_streak)) % MOD;
        }
        return ret;
    }
}

int solve()
{
    std::memset(dp, -1, sizeof(dp));
    int ans = solve(1, 0, 0);
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}