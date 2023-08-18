#include <bits/stdc++.h>

int n, m;
int board[102][102];

void getinput()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> board[i][j];
        }
    }
}

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int solve()
{
    // 정사영이 아니고
    // 가려지는 부분의 넓이도 포함해야

    int area = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int h = 1; h <= board[i][j]; h++)
            {
                // 위
                if (h == board[i][j])
                    area++;
                // 바닥
                if (h == 1)
                    area++;
                for (int k = 0; k < 4; k++)
                {
                    int nr = i + dr[k], nc = j + dc[k];
                    if (board[nr][nc] < h)
                        area++;
                }
            }
        }
    }
    return area;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}