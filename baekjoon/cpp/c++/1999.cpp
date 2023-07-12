#include <bits/stdc++.h>

int n, b, k;
int matrix[251][251];
int rmax[251][251], rmin[251][251];

void getinput()
{
    std::cin >> n >> b >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void preprocess()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - b + 1; j++)
        {
            int max = 0, min = 251;
            for (int k = 0; k < b; k++)
            {
                max = std::max(max, matrix[i][j + k]);
                min = std::min(min, matrix[i][j + k]);
            }
            rmax[i][j] = max;
            rmin[i][j] = min;
        }
    }
}

int solve(int i, int j)
{
    int max = 0, min = 251;
    for (int k = 0; k < b; k++)
    {
        max = std::max(max, rmax[i + k][j]);
        min = std::min(min, rmin[i + k][j]);
    }
    return max - min;
}

void solve()
{
    preprocess();

    for (int a = 0; a < k; a++)
    {
        int i, j;
        std::cin >> i >> j;
        std::cout << solve(i, j) << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}