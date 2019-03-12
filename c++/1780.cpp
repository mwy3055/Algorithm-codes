#include <iostream>
using namespace std;

int n, cnt[3];
short map[2187][2187];

void div(int y, int x, int size)
{
    int check = map[y][x];
    bool flag = true;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (map[y + i][x + j] != map[y][x])
            {
                flag = false;
                break;
            }
        }
    }
    
    if (flag)
    {
        cnt[check + 1]++;
        return;
    }
    //종이 분할
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            div(y + i * size / 3, x + j * size / 3, size / 3);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    div(0, 0, n);
    cout << cnt[0] << '\n'
         << cnt[1] << '\n'
         << cnt[2];
}