#include <bits/stdc++.h>
using namespace std;

int paper[128][128];
int white, blue;

bool allwhite(int &y, int &x, int &size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (paper[y + i][x + j] == 1)
                return false;
    white++;
    return true;
}

bool allblue(int &y, int &x, int &size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (paper[y + i][x + j] == 0)
                return false;
    blue++;
    return true;
}

void divide(int y, int x, int size)
{
    if (allwhite(y, x, size) || allblue(y, x, size))
        return;

    int div = size / 2;
    divide(y, x, div);
    divide(y + div, x, div);
    divide(y, x + div, div);
    divide(y + div, x + div, div);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> paper[i][j];

    divide(0, 0, size);
    cout << white << '\n'
         << blue;
}