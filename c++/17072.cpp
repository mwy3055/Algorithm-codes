//2019 연세대학교 컴퓨터과학과 프로그래밍 경진대회 Open Contest A번
#include <bits/stdc++.h>
using namespace std;

int intensity(int &r, int &g, int &b)
{
    return 2126 * r + 7152 * g + 722 * b;
}

char ascii_generator(int &r, int &g, int &b)
{
    int Intensity = intensity(r, g, b);
    if (0 <= Intensity && Intensity < 510000)
        return '#';
    if (510000 <= Intensity && Intensity < 1020000)
        return 'o';
    if (1020000 <= Intensity && Intensity < 1530000)
        return '+';
    if (1530000 <= Intensity && Intensity < 2040000)
        return '-';
    else
        return '.';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int r, g, b;
            cin >> r >> g >> b;
            cout << ascii_generator(r, g, b);
        }
        cout << '\n';
    }
}