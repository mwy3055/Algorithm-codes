#include <bits/stdc++.h>
using namespace std;

int n;
char MAP[1000][1000]; //지뢰:'*', 주변개수:숫자로 저장, 나중에 '0'+a 하면 됨

bool isin(int &y, int &x)
{
    return 0 <= y && y < n && 0 <= x && x < n;
}
bool isnum(int &y, int &x)
{
    return 0 <= MAP[y][x] && MAP[y][x] <= 9;
}
void addmine(int &y, int &x, int num)
{
    static int src[][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

    for (int i = 0; i < 8; i++)
    {
        int sy = y + src[i][0], sx = x + src[i][1];
        if (isin(sy, sx) && isnum(sy, sx) && MAP[sy][sx] + num >= 10)
        {
            MAP[sy][sx] = 'M';
        }
        else if (isin(sy, sx) && isnum(sy, sx))
        {
            MAP[sy][sx] += num;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (c != '.') //지뢰
            {
                MAP[i][j] = '*';
                addmine(i, j, c - '0');
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isnum(i, j))
                cout << (char)(MAP[i][j] + '0');
            else
            {
                cout << MAP[i][j];
            }
        }
        cout << '\n';
    }
}