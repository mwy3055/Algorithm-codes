#include <bits/stdc++.h>

int s[11][11], dp[1 << 11][1 << 11];
const int INF = 0x3f3f3f3f;

void getinput()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            std::cin >> s[i][j];
        }
    }
}

// 현재 배치된 선수의 집합이 player_bit이고, 선수가 배치되어 있는 자리의 집합이 pos_bit일 때
// 선수를 추가로 배치해서 만들 수 있는 능력치의 합의 최댓값
int solve(int player_bit, int pos_bit, int dep)
{
    if (dep == 11)
        return ((player_bit == (1 << 11) - 1) && (pos_bit == (1 << 11) - 1) ? 0 : -INF);
    auto &ret = dp[player_bit][pos_bit];
    if (ret != -1)
        return ret;
    for (int player = 0; player < 11; player++)
    {
        if (player_bit & (1 << player))
            continue;
        for (int pos = 0; pos < 11; pos++)
        {
            if ((pos_bit & (1 << pos)) || s[player][pos] == 0)
                continue;
            int more = solve(player_bit | (1 << player), pos_bit | (1 << pos), dep + 1);
            ret = std::max(ret, more + s[player][pos]);
        }
        // 한명만 해도 됨; 나머지는 다른 재귀에서 계산될 것
        break;
    }
    // 더 이상 배치할 수 있는 방법이 없는 경우, 불가능함을 표시하기 위해 매우 작은 값 할당
    if (ret == -1)
        ret = -INF;
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int c;
    std::cin >> c;
    while (c--)
    {
        memset(dp, -1, sizeof(dp));
        getinput();
        std::cout << solve(0, 0, 0) << '\n';
    }
}