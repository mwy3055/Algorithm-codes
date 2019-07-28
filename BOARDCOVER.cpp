#include <bits/stdc++.h>
using namespace std;

char board[20][21];
int src[][3][2] = {0, 0, 1, 0, 1, -1,
                   0, 0, 1, 0, 1, 1,
                   0, 0, 0, 1, 1, 1,
                   0, 0, 1, 0, 0, 1};

int countblank(int &h, int &w)
{
    int cnt = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (board[i][j] == '.')
                cnt++;
    return cnt;
}
bool isin(int &h, int &w, int y, int x)
{
    return 0 <= y && y < h && 0 <= x && x < w;
}
bool cancover(int &h, int &w, int y, int x, int block)
{
    for (int i = 0; i < 3; i++)
    {
        int sy = y + src[block][i][0], sx = x + src[block][i][1];
        if (!(isin(h, w, sy, sx) && board[sy][sx] == '.'))
            return false;
    }
    return true;
}
void setboard(int y, int x, int block, char c)
{
    for (int i = 0; i < 3; i++)
    {
        int sy = y + src[block][i][0], sx = x + src[block][i][1];
        board[sy][sx] = c;
    }
}
void findblank(int &h, int &w, int &y, int &x)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (board[i][j] == '.')
            {
                y = i, x = j;
                return;
            }
        }
    }
}
int solve(int &h, int &w, int n)
{
    if (n == 0)
        return 1;

    int ans = 0, y, x;
    findblank(h, w, y, x);

    for (int i = 0; i < 4; i++)
    {
        if (cancover(h, w, y, x, i))
        {
            setboard(y, x, i, '#');
            ans += solve(h, w, n - 1);
            setboard(y, x, i, '.');
        }
    }

    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    while (c--)
    {
        int h, w;
        cin >> h >> w;
        for (int i = 0; i < h; i++)
            cin >> board[i];

        int n = countblank(h, w);
        if (n % 3)
        {
            cout << 0 << '\n';
            continue;
        }
        n /= 3;

        cout << solve(h, w, n) << '\n';
    }
}