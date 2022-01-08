#include <bits/stdc++.h>
using namespace std;

int m, n; //Çà, ¿­ ¼ö
int src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
bool visit[100][100] = {false};

enum direction
{
    RIGHT,
    DOWN,
    LEFT,
    UP
};

bool isin(int y, int x)
{
    return 0 <= y && y < m && 0 <= x && x < n;
}
direction next(direction &dir)
{
    switch (dir)
    {
    case direction::RIGHT:
        return direction::DOWN;
    case direction::DOWN:
        return direction::LEFT;
    case direction::LEFT:
        return direction::UP;
    default:
        return direction::RIGHT;
    }
}
bool next_dir(int &y, int &x, direction &dir)
{
    int ny = y + src[dir][0], nx = x + src[dir][1];
    if (!isin(ny, nx) || visit[ny][nx])
    {
        dir = next(dir);
        return true;
    }
    return false;
}
void next_room(int &y, int &x, direction &dir)
{
    y += src[dir][0];
    x += src[dir][1];
}

int main()
{
    cin >> m >> n;

    int y = 0, x = 0;
    direction dir = direction::RIGHT;

    int ans = 0;
    while (!visit[y][x])
    {
        visit[y][x] = true;

        if (next_dir(y, x, dir))
        {
            ans++;
        }
        next_room(y, x, dir);
    }

    cout << ans - 1;
}