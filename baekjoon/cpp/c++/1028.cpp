#include <bits/stdc++.h>

int r, c;
char map[751][751];

int leftup[750][750];
int leftdown[750][750];
int rightup[750][750];
int rightdown[750][750];

void getinput()
{
    std::cin >> r >> c;
    for (int i = 0; i < r; i++)
        std::cin >> map[i];
}

bool isin(int y, int x)
{
    return 0 <= y && y < r && 0 <= x && x < c;
}

int get(int (*arr)[750], int y, int x)
{
    if (isin(y, x))
        return arr[y][x];
    else
        return 0;
}

void fill_dp()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] == '1')
            {
                leftup[i][j] = get(leftup, i - 1, j - 1) + 1;
                rightup[i][j] = get(rightup, i - 1, j + 1) + 1;
            }
        }
    }

    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] == '1')
            {
                leftdown[i][j] = get(leftdown, i + 1, j - 1) + 1;
                rightdown[i][j] = get(rightdown, i + 1, j + 1) + 1;
            }
        }
    }
}

int solve()
{
    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // (i, j)가 위 꼭짓점일 때: 아래 꼭짓점을 확인하자
            int max_len = std::min(leftdown[i][j], rightdown[i][j]);
            for (int l = 1; l <= max_len; l++)
            {
                int down_r = i + (l - 1) * 2, down_c = j;
                if (isin(down_r, down_c) &&
                    leftup[down_r][down_c] >= l &&
                    rightup[down_r][down_c] >= l)
                {
                    ans = std::max(ans, l);
                }
            }
            // (i, j)가 왼쪽 꼭짓점일 때: 오른쪽 꼭짓점을 확인하자
            max_len = std::min(rightup[i][j], rightdown[i][j]);
            for (int l = 1; l <= max_len; l++)
            {
                int right_r = i, right_c = j + (l - 1) * 2;
                if (isin(right_r, right_c) &&
                    leftup[right_r][right_c] >= l &&
                    leftdown[right_r][right_c] >= l)
                {
                    ans = std::max(ans, l);
                }
            }
            // 나머지를 확인하지 않아도 되는 이유: 이전 루프에서 확인함
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    fill_dp();
    std::cout << solve() << '\n';
}