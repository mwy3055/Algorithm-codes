#include <bits/stdc++.h>

char map[1001][1001];
int jungle[1001][1001], ocean[1001][1001], ice[1001][1001];

void preprocess(int m, int n, char c, int (*arr)[1001])
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + (map[i][j] == c);
        }
    }
}

int calc(int a, int b, int c, int d, int (*arr)[1001])
{
    return arr[c][d] - arr[c][b - 1] - arr[a - 1][d] + arr[a - 1][b - 1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int m, n, k;
    std::cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> map[i][j];

    preprocess(m, n, 'J', jungle);
    preprocess(m, n, 'O', ocean);
    preprocess(m, n, 'I', ice);

    for (int i = 0; i < k; i++)
    {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        std::cout << calc(a, b, c, d, jungle) << ' ' << calc(a, b, c, d, ocean) << ' ' << calc(a, b, c, d, ice) << '\n';
    }
}