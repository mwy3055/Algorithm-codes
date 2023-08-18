#include <bits/stdc++.h>

std::vector<int> bitmasks;
char dp[(1 << 25) + 1];

// 새로 놓을 수 있는 모든 블럭의 bitmask 계산
void calc_bitmask()
{
    // |
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int bit = 0;
            bit |= 1 << (i * 5 + j);
            bit |= 1 << ((i + 1) * 5 + j);
            bitmasks.push_back(bit);
        }
    }

    // ㅡ
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int bit = 0;
            bit |= 1 << (i * 5 + j);
            bit |= 1 << (i * 5 + j + 1);
            bitmasks.push_back(bit);
        }
    }

    // ㄴ
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int bit = 0;
            bit |= 1 << (i * 5 + j);
            bit |= 1 << ((i + 1) * 5 + j);
            bit |= 1 << ((i + 1) * 5 + (j + 1));
            bitmasks.push_back(bit);
        }
    }
    // ㄴ 좌우반전
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int bit = 0;
            bit |= 1 << (i * 5 + j + 1);
            bit |= 1 << ((i + 1) * 5 + j);
            bit |= 1 << ((i + 1) * 5 + (j + 1));
            bitmasks.push_back(bit);
        }
    }
    // ㄱ
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int bit = 0;
            bit |= 1 << (i * 5 + j);
            bit |= 1 << (i * 5 + j + 1);
            bit |= 1 << ((i + 1) * 5 + (j + 1));
            bitmasks.push_back(bit);
        }
    }
    // ㄱ 좌우반전
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int bit = 0;
            bit |= 1 << (i * 5 + j);
            bit |= 1 << (i * 5 + j + 1);
            bit |= 1 << ((i + 1) * 5 + j);
            bitmasks.push_back(bit);
        }
    }
}

// 보드의 상태가 state일 때, 이번 턴에 놓는 사람이 이길 수 있는가?
// (i/5, i%5)번 칸이 비어 있다면 (state & (1 << i)) != 0
// (0 <= i < 25)
bool can_win(int state)
{
    auto &ret = dp[state];
    if (ret != -1)
        return ret;

    for (auto &mask : bitmasks)
    {
        if ((state & mask) == 0)
        {
            if (can_win(state | mask) == false)
                return ret = 1;
        }
    }
    return ret = 0;
}

// 게임판을 입력받고, 판의 상태를 비트마스크로 반환
int get_state()
{
    char c;
    int rtn = 0;
    for (int i = 0; i < 25; i++)
    {
        std::cin >> c;
        if (c == '#')
            rtn |= (1 << i);
    }
    return rtn;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    memset(dp, -1, sizeof(dp));
    calc_bitmask();
    int c;
    std::cin >> c;
    while (c--)
    {
        auto state = get_state();
        std::cout << (can_win(state) ? "WINNING" : "LOSING") << '\n';
    }
}