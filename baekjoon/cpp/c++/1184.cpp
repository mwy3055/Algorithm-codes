#include <bits/stdc++.h>

using pii = std::pair<int, int>;
using ppipi = std::pair<pii, pii>;

int n, map[51][51], sum[51][51]; // (1, 1) ~ (i, j)
int subsum[51][51][51][51];

void getinput()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> map[i][j];
        }
    }
}

void preprocess()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] = map[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    for (int r1 = 1; r1 <= n; r1++)
    {
        for (int c1 = 1; c1 <= n; c1++)
        {
            for (int r2 = r1; r2 <= n; r2++)
            {
                for (int c2 = c1; c2 <= n; c2++)
                {
                    subsum[r1][c1][r2][c2] = sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1 - 1][c1 - 1];
                }
            }
        }
    }
}

// 좌상 ?= 우하
// 매개변수는 선 기준
// 칸 기준: [r2, c2] ~ [r1-1, c1-1] ?= [r1, c1] ~ [r3-1, c3-1]
int search_1(int r1, int c1)
{
    // for문을 펼치는 것이 핵심!
    // [r1, c1]의 좌상단에 있는 모든 합을 구한다.
    auto sums = std::unordered_map<int, int>();
    for (int r2 = 1; r2 < r1; r2++)
    {
        for (int c2 = 1; c2 < c1; c2++)
        {
            auto sub = subsum[r2][c2][r1 - 1][c1 - 1];
            sums[sub]++;
        }
    }
    // [r1, c1]의 우하단에 있는 합을 본다.
    int result = 0;
    for (int r3 = r1 + 1; r3 <= n + 1; r3++)
    {
        for (int c3 = c1 + 1; c3 <= n + 1; c3++)
        {
            auto sub = subsum[r1][c1][r3 - 1][c3 - 1];
            result += sums[sub];
        }
    }
    return result;
}

// 좌하 ?= 우상
// 매개변수는 선 기준
// 칸 기준: [r1, c2] ~ [r2-1, c1-1] ?= [r3, c1] ~ [r1-1, c3-1]
int search_2(int r1, int c1)
{
    // [r1, c1]의 좌하단에 있는 합을 센다.
    auto sums = std::unordered_map<int, int>();
    for (int r2 = r1 + 1; r2 <= n + 1; r2++)
    {
        for (int c2 = 1; c2 < c1; c2++)
        {
            auto sub = subsum[r1][c2][r2 - 1][c1 - 1];
            sums[sub]++;
        }
    }
    // [r1, c1]의 우상단에 있는 합을 본다.
    int result = 0;
    for (int r3 = 1; r3 < r1; r3++)
    {
        for (int c3 = c1 + 1; c3 <= n + 1; c3++)
        {
            auto sub = subsum[r3][c1][r1 - 1][c3 - 1];
            result += sums[sub];
        }
    }
    return result;
}

// (r1, c1): 두 사각형이 만나는 점
int search(int r1, int c1)
{
    int result = 0;
    // 좌상 ?= 우하
    result += search_1(r1, c1);
    // 좌하 ?= 우상
    result += search_2(r1, c1);
    return result;
}

int solve()
{
    preprocess();

    int ans = 0;
    for (int r1 = 2; r1 <= n; r1++)
    {
        for (int c1 = 2; c1 <= n; c1++)
        {
            auto result = search(r1, c1);
            ans += result;
        }
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