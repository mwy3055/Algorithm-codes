#include <iostream>
using namespace std;

int r, c, ans = 0;
bool flag = false;

bool isin(int i, int j, int y, int x, int siz)
{
    return y <= i && i < y + siz && x <= j && j < x + siz;
}

void div(int y, int x, int size)
{
    int src[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    if (size == 2)
    {
        for (int i = 0; i < 4; i++)
        {
            int sy = y + src[i][0], sx = x + src[i][1];
            ans++;
            if (sy == r && sx == c)
            {
                flag = true;
                return;
            }
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (!flag)
        {
            int sy = y + (size / 2) * src[i][0], sx = x + (size / 2) * src[i][1];
            if (isin(r, c, sy, sx, size / 2))
                div(sy, sx, size / 2);
            else
                ans += size * size / 4;
        }
        else
            return;
    }
}

int main()
{
    int n;
    cin >> n >> r >> c;

    div(0, 0, 1 << n);
    cout << ans - 1;
}