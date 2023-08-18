#include <bits/stdc++.h>

std::string s;
std::vector<std::string> a;
int dp[101];

void getinput()
{
    std::cin >> s;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::string aa;
        std::cin >> aa;
        a.push_back(aa);
    }
}

bool solve()
{
    std::memset(dp, -1, sizeof(dp));
    // dp[i]: S[0:i](inclusive)를 만들 수 있는가?
    int len = s.length();
    dp[len] = 1; // 문자열 끝났으니까 true

    for (int i = len - 1; i >= 0; i--)
    {
        auto result = 0;
        for (auto &aa : a)
        {
            if (s.substr(i, aa.length()) == aa &&
                (i + aa.length() <= len && dp[i + aa.length()] == 1))
            {
                result = 1;
                break;
            }
        }
        dp[i] = result;
    }
    return dp[0] == 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}