#include <bits/stdc++.h>
using namespace std;

int n, a[21][21];

bool condition(int &x, int &y, int &d1, int &d2)
{
    return (x + d1 + d2 <= n) &&
           (1 <= y - d1) && (y + d2 <= n);
}

int solve(int &x, int &y, int &d1, int &d2)
{
    int pop[6] = {0}, index[21][21] = {0};
    for (int r = x, c = y; r <= x + d2 && c <= y + d2; r++, c++)
        index[r][c] = 5;
    for (int r = x, c = y; r <= x + d1 && c >= y - d1; r++, c--)
        index[r][c] = 5;
    for (int r = x + d1, c = y - d1; r <= x + d1 + d2 && c <= y - d1 + d2; r++, c++)
        index[r][c] = 5;
    for (int r = x + d2, c = y + d2; r <= x + d1 + d2 && c >= y - d1 + d2; r++, c--)
        index[r][c] = 5;

    for (int r = 1; r < x + d1; r++)
    {
        for (int c = 1; c <= y; c++)
        {
            if (index[r][c] == 5)
                break;
            index[r][c] = 1;
        }
    }
    for (int r = 1; r <= x + d2; r++)
    {
        int c = y + 1;
        if (x < r)
        {
            c += (r - x);
        }
        for (; c <= n; c++)
        {
            if (index[r][c] == 5)
                continue;
            index[r][c] = 2;
        }
    }
    for (int r = x + d1; r <= n; r++)
    {
        for (int c = 1; c < y - d1 + d2; c++)
        {
            if (index[r][c] == 5)
                break;
            index[r][c] = 3;
        }
    }
    for (int r = x + d2 + 1; r <= n; r++)
    {
        int c = y - d1 + d2;
        if (r <= x + d1 + d2)
        {
            c += (x + d1 + d2 - r + 1);
        }
        for (; c <= n; c++)
        {
            if (index[r][c] == 5)
                continue;
            index[r][c] = 4;
        }
    }

    int total = 0;
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            pop[index[r][c]] += a[r][c];
            total += a[r][c];
        }
    }
    pop[5] = total - (pop[1] + pop[2] + pop[3] + pop[4]);
    sort(pop + 1, pop + 6);
    return abs(pop[1] - pop[5]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    int ans = 0x7fffffff;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            for (int d1 = 1; d1 <= n; d1++)
            {
                for (int d2 = 1; d2 <= n; d2++)
                {
                    if (condition(x, y, d1, d2))
                        ans = min(ans, solve(x, y, d1, d2));
                }
            }
        }
    }

    cout << ans;
}