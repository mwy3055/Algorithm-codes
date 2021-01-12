#include <bits/stdc++.h>

using board = int[3][3];
const int INF = 19683; // 3^9
int fac3[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561};
int dp[INF];
char map[3][3]; // 입력으로 주어지는 게임판

int get_digit(int val, int i) // val을 3진수로 나타낸 값의 i번째 자릿수를 얻음 (0 <= i < 9)
{
    return (val / fac3[i]) % 3;
}

int set_digit(int val, int i, int j) // val을 3진수로 나타낸 값의 i번째 자릿수를 j로 설정
{
    return val + (j - get_digit(val, i)) * fac3[i];
}

// player 1: x
// player 2: o

bool check_win(board b, int player)
{
    for (int i = 0; i < 3; i++)
    {
        bool check = true;
        for (int j = 0; j < 3; j++)
        {
            if (b[i][j] != player)
            {
                check = false;
                break;
            }
        }
        if (check)
            return true;
    }

    for (int j = 0; j < 3; j++)
    {
        bool check = true;
        for (int i = 0; i < 3; i++)
        {
            if (b[i][j] != player)
            {
                check = false;
                break;
            }
        }
        if (check)
            return true;
    }
    if (b[0][0] == player && b[1][1] == player && b[2][2] == player)
        return true;
    if (b[0][2] == player && b[1][1] == player && b[2][0] == player)
        return true;
    return false;
}

int get_winner(int val)
{
    board b;
    for (int i = 0; i < 9; i++)
    {
        b[i / 3][i % 3] = get_digit(val, i);
    }

    int winner = 0;
    if (check_win(b, 1))
        winner = 1;
    else if (check_win(b, 2))
        winner = 2;
    return winner;
}

bool is_finish(int val)
{
    if (get_winner(val))
        return true;
    for (int i = 0; i < 9; i++)
    {
        if (get_digit(val, i) == 0)
            return false;
    }
    return true;
}

int get_cur_player(int val) // 보드판의 상태가 val일 때, 이번에 돌을 놓는 사람의 번호를 반환
{
    int p1 = 0, p2 = 0;
    for (int i = 0; i < 9; i++)
    {
        int digit = get_digit(val, i);
        if (digit == 1)
            p1++;
        else if (digit == 2)
            p2++;
    }
    if (p1 == p2)
        return 1;
    else
        return 2;
}

int get_board_state()
{
    int rtn = 0;
    for (int i = 0; i < 9; i++)
    {
        int r = i / 3, c = i % 3;
        if (map[r][c] == '.')
            continue;
        else if (map[r][c] == 'x')
            rtn = set_digit(rtn, i, 1);
        else
            rtn = set_digit(rtn, i, 2);
    }
    return rtn;
}

// 보드의 상태가 state일 때
// 이번에 돌을 놓는 사람이 이길 수 있으면 1을
// 무조건 진다면 2를 반환
// 이기지는 못해도 비긴다면 0을
int solve(int state)
{
    auto &ret = dp[state];
    int turn = get_cur_player(state);
    if (is_finish(state))
    {
        int winner = get_winner(state);
        if (winner == 0)
            return ret = winner;
        else
            return ret = (turn == winner ? 1 : 2);
    }
    if (ret != -1)
        return ret;
    // 모든 수를 놓아본다.
    for (int i = 0; i < 9; i++)
    {
        if (get_digit(state, i) == 0)
        {
            int next_state = set_digit(state, i, turn);
            int result = solve(next_state);
            // 이 수를 둬서 무조건 이길 수 있다면 즉시 종료
            if (result == 2)
            {
                ret = 1;
                break;
            }
            // 비길 수 있다면 일단 보류
            else if (result == 0)
            {
                ret = 0;
            }
        }
    }
    // 뭘 해도 이기거나 비길 수 없다면 진 것
    if (ret == -1)
        ret = 2;
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
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cin >> map[i][j];
            }
        }
        int state = get_board_state();
        int first_player = get_cur_player(state);
        int result = solve(state);
        if (result == 0)
            std::cout << "TIE" << '\n';
        else if (result == 1)
            std::cout << (first_player == 1 ? 'x' : 'o') << '\n';
        else
            std::cout << (first_player == 1 ? 'o' : 'x') << '\n';
    }
}