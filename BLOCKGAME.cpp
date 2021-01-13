#include <bits/stdc++.h>

char dp[1 << 25];

// 보드의 상태가 state일 때, 이번 턴에 놓는 사람이 이길 수 있는가?
// (i/5, i%5)번 칸이 비어 있다면 (state & (1 << i)) != 0
// (0 <= i < 25)
// board[5][5] 대신 비트마스크를 이용하면 더 빠르게 계산할 수 있음
bool can_win(int state)
{
    auto &ret = dp[state];
    if (ret != -1)
        return ret;

    bool board[5][5];
    for (int i = 0; i < 25; i++)
    {
        board[i / 5][i % 5] = ((state & (1 << i)) != 0);
    }

    // |
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (!board[i][j] && !board[i + 1][j])
            {
                auto new_state = state;
                new_state |= 1 << (i * 5 + j);
                new_state |= 1 << ((i + 1) * 5 + j);
                if (can_win(new_state) == false)
                    return ret = 1;
            }
        }
    }

    // ㅡ
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!board[i][j] && !board[i][j + 1])
            {
                auto new_state = state;
                new_state |= 1 << (i * 5 + j);
                new_state |= 1 << (i * 5 + (j + 1));
                if (can_win(new_state) == false)
                    return ret = 1;
            }
        }
    }

    // ㄴ
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!board[i][j] && !board[i + 1][j] && !board[i + 1][j + 1])
            {
                auto new_state = state;
                new_state |= 1 << (i * 5 + j);
                new_state |= 1 << ((i + 1) * 5 + j);
                new_state |= 1 << ((i + 1) * 5 + (j + 1));
                if (can_win(new_state) == false)
                    return ret = 1;
            }
        }
    }
    // ㄴ 좌우반전
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!board[i][j + 1] && !board[i + 1][j] && !board[i + 1][j + 1])
            {
                auto new_state = state;
                new_state |= 1 << (i * 5 + (j + 1));
                new_state |= 1 << ((i + 1) * 5 + j);
                new_state |= 1 << ((i + 1) * 5 + (j + 1));
                if (can_win(new_state) == false)
                    return ret = 1;
            }
        }
    }
    // ㄱ
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!board[i][j] && !board[i][j + 1] && !board[i + 1][j + 1])
            {
                auto new_state = state;
                new_state |= 1 << (i * 5 + j);
                new_state |= 1 << (i * 5 + (j + 1));
                new_state |= 1 << ((i + 1) * 5 + (j + 1));
                if (can_win(new_state) == false)
                    return ret = 1;
            }
        }
    }
    // ㄱ 좌우반전
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!board[i][j] && !board[i][j + 1] && !board[i + 1][j])
            {
                auto new_state = state;
                new_state |= 1 << (i * 5 + j);
                new_state |= 1 << (i * 5 + (j + 1));
                new_state |= 1 << ((i + 1) * 5 + j);
                if (can_win(new_state) == false)
                    return ret = 1;
            }
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
    int c;
    std::cin >> c;
    while (c--)
    {
        auto state = get_state();
        std::cout << (can_win(state) ? "WINNING" : "LOSING") << '\n';
    }
}