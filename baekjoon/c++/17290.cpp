#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    r--, c--;

    bool blank[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            blank[i][j] = true;

    for (int i = 0; i < 10; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < 10; j++)
            if (str[j] == 'o')
            {
                for (int y = 0; y < 10; y++)
                    blank[y][j] = false;
                for (int x = 0; x < 10; x++)
                    blank[i][x] = false;
            }
    }

    int ans = 0x7fffffff;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (blank[i][j])
                ans = min(ans, abs(r - i) + abs(c - j));
        }
    }
    cout << ans;
}
