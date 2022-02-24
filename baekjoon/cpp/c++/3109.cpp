#include <bits/stdc++.h>

int src[][2] = {-1, 1, 0, 1, 1, 1};
char map[10000][501];
bool visit[10000][500];

bool isin(int &r, int &c, int &y, int &x)
{
    return 0 <= y && y < r && 0 <= x && x < c;
}

bool search(int &r, int &c, int &y, int &x)
{
    visit[y][x] = true;
    if (x == c - 1)
        return true;
    for (int i = 0; i < 3; i++)
    {
        int ny = y + src[i][0], nx = x + src[i][1];
        if (isin(r, c, ny, nx) && !visit[ny][nx] && map[ny][nx] == '.')
        {
            if (search(r, c, ny, nx))
                return true;
        }
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int r, c;
    std::cin >> r >> c;
    for (int i = 0; i < r; i++)
        std::cin >> map[i];

    int ans = 0, x = 0;
    for (int i = 0; i < r; i++)
    {
        if (search(r, c, i, x))
            ans++;
    }
    std::cout << ans;
}