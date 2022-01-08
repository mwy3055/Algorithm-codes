#include <bits/stdc++.h>
using namespace std;

int n, m, b;
int ground[500][500];

void test(int &h, int &dig, int &pile)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ground[i][j] < h)
            {
                pile += h - ground[i][j];
            }
            else if (h < ground[i][j])
            {
                dig += ground[i][j] - h;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> b;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> ground[i][j];

    int mtime = 0x7fffffff, mheight = 256;
    for (int h = 256; h >= 0; h--) // 가장 낮은 높이까지만 탐색해도 됨
    {
        int dig = 0, pile = 0;
        test(h, dig, pile);
        if (dig + b < pile)
            continue;
        int time = 2 * dig + pile;
        if (time < mtime)
        {
            mtime = time;
            mheight = h;
        }
    }

    cout << mtime << ' ' << mheight;
}