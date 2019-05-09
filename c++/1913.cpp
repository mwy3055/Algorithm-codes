#include <bits/stdc++.h>
using namespace std;

int sq[999][999];

bool isin(int &y, int &x, int &n)
{
    return 0 <= y && y < n && 0 <= x && x < n;
}
void change_coord(int &y, int &x, int &dir, int &n)
{
    static int src[][2] = {1, 0, 0, 1, -1, 0, 0, -1};
    int sy = y + src[dir][0], sx = x + src[dir][1];
    //if map out...
    if (!isin(sy, sx, n) || sq[sy][sx] != 0)
    {
        dir = (dir + 1) % 4;
        sy = y + src[dir][0], sx = x + src[dir][1];
    }
    y = sy, x = sx;
}
void makemap(int &n, int &m, int &my, int &mx)
{
    int y = 0, x = 0, dir = 0;
    for (int i = n * n; i > 0; i--)
    {
        if (i == m)
        {
            my = y, mx = x;
        }
        sq[y][x] = i;
        change_coord(y, x, dir, n);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int my, mx;
    makemap(n, m, my, mx);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << sq[i][j] << ' ';
        cout << '\n';
    }
    cout << my + 1 << ' ' << mx + 1;
}