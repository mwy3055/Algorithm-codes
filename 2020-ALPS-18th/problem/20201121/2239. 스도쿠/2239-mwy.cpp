#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int board[9][9];
vector<pii> empties;

bool check(int i, int j)
{
    int hor[10] = {0}, ver[10] = {0}, sq[10] = {0};
    for (int x = 0; x < 9; x++)
        hor[board[i][x]]++;
    for (int y = 0; y < 9; y++)
        ver[board[y][j]]++;

    int sy = (i / 3) * 3, sx = (j / 3) * 3;
    for (int cy = sy; cy < sy + 3; cy++)
        for (int cx = sx; cx < sx + 3; cx++)
            sq[board[cy][cx]]++;

    for (int i = 1; i <= 9; i++)
    {
        if (1 < hor[i] || 1 < ver[i] || 1 < sq[i])
            return false;
    }
    return true;
}
bool solve(int idx)
{
    if (idx == empties.size())
    {
        return solved();
    }

    int y = empties[idx].first, x = empties[idx].second;
    for (int c = 1; c <= 9; c++)
    {
        board[y][x] = c;
        if (check(y, x) && solve(idx + 1))
            return true;
        else
            board[y][x] = 0;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    char c;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> c;
            board[i][j] = c - '0';
            if (!board[i][j])
                empties.push_back({i, j});
        }
    }

    solve(0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j];
        cout << '\n';
    }
}