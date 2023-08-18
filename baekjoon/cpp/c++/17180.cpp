#include <bits/stdc++.h>

int dp[301][301];

void getinput(std::string &a, std::string &b)
{
    int n, m;
    std::cin >> n >> m >> a >> b;
}

int diff(char a, char b)
{
    return std::abs(a - b);
}

int solve(std::string &a, std::string &b)
{
    std::memset(dp, 0x3f, sizeof(dp)); // INF
    dp[0][0] = 0;

    /* 편집거리 알고리즘: 문자열 A를 B로 바꾸는 데 드는 비용
        dp[i][j] = min(
            dp[i][j - 1] + B에 B[j]를 삽입하는 비용,
            dp[i - 1][j] + A에서 A[i]를 삭제하는 비용,
            dp[i-1][j-1] + A[i]를 B[j]로 대체하는 비용
        ) (전부 1-indexed)
        여기서는 모든 비용이 (문자의 차이)이다.
    */
    auto la = a.length(), lb = b.length();
    for (int i = 1; i <= la; i++)
    {
        for (int j = 1; j <= lb; j++)
        {
            dp[i][j] = std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + diff(a[i - 1], b[j - 1]);
        }
    }
    return dp[la][lb];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string a, b;
    getinput(a, b);
    std::cout << solve(a, b) << '\n';
}