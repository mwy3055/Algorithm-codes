#include <bits/stdc++.h>

int h, w;
int height[500];
int board[500][500];

void getinput()
{
    std::cin >> h >> w;
    for (int i = 0; i < w; i++)
    {
        std::cin >> height[i];
    }
}

int solve()
{
    // 0: 물
    // 1: 블록
    // 2: 빈 공간
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < height[i]; j++)
        {
            board[i][j] = 1;
        }
    }

    for (int j = 0; j < h; j++)
    {
        // (0, j)에서 오른쪽으로 지움
        for (int i = 0; i < w; i++)
        {
            if (board[i][j] == 1)
                break;
            else if (board[i][j] == 0)
                board[i][j] = 2;
        }

        // (w-1, j)에서 왼쪽으로 지움
        for (int i = w - 1; i >= 0; i--)
        {
            if (board[i][j] == 1)
                break;
            else if (board[i][j] == 0)
                board[i][j] = 2;
        }
    }

    int ans = 0;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (board[i][j] == 0)
                ans++;
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