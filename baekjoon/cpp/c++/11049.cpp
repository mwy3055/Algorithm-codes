// 1~j 구간을 1~(k-1), k~j 구간으로 나눠 재귀적으로 최솟값을 구한다.

#include <bits/stdc++.h>
using namespace std;

#define r first
#define c second
typedef pair<int, int> Matrix;

int dp[501][501];
Matrix mat[501];

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
}

int count(Matrix a, Matrix b)
{
    return a.r * b.r * b.c;
}

Matrix multiply(Matrix a, Matrix b)
{
    return Matrix{a.r, b.c};
}

int solve(int s, int e)
{
    if (s == e)
        return dp[s][e] = 0;
    else if (dp[s][e] != -1)
        return dp[s][e];

    int ans = 0x7fffffff;
    for (int k = s + 1; k <= e; k++)
    {
        ans = min(ans, solve(s, k - 1) + solve(k, e) + mat[s].r * mat[k].r * mat[e].c);
    }

    return dp[s][e] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    init(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> mat[i].r >> mat[i].c;
    }

    cout << solve(1, n);
}