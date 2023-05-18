#include <bits/stdc++.h>

int n, m;
std::string board, str;
int dp[5000][5000];

void getinput()
{
    std::cin >> n >> m >> board >> str;
}

int search(int i, int j)
{
    auto &ret = dp[i][j];
    if (ret != -1)
        return ret;

    ret = 0;
    if (i - 1 >= 0 && j + 1 < m)
        ret = search(i - 1, j + 1); // L
    if (i + 1 < n && j + 1 < m)
        ret = std::max(ret, search(i + 1, j + 1)); // R
    ret += board[i] == str[j];
    return ret;
}

int solve()
{
    std::memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = std::max(ans, search(i, 0));
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