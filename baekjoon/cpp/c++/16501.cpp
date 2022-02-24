#include <bits/stdc++.h>

// 만족도 점수*100을 반환
int get_diff(int s1, int s2, int t1, int t2)
{
    return 100 - 5 * std::abs((s1 + s2) - (t1 + t2));
}

void solve(std::vector<int> &s)
{
    int ans = 0;
    std::sort(s.begin(), s.end());
    do
    {
        int score1 = get_diff(s[0], s[1], s[2], s[3]);
        int score2 = get_diff(s[4], s[5], s[6], s[7]);
        ans = std::max(ans, std::min(score1, score2));
    } while (std::next_permutation(s.begin(), s.end()));
    if (ans % 10 == 0)
    {
        std::cout << ans / 100 << '.' << (ans % 100) / 10;
    }
    else
    {
        std::cout << "0." << ans / 10 << ans % 10;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<int> scores(8);
    for (auto &s : scores)
        std::cin >> s;

    solve(scores);
}