#include <bits/stdc++.h>

// trans[i][j]: i번째 날에 상태가 j로 바뀐 짚신벌레의 수
// sum[i][j]: i번째 날에 상태가 j인 짚신벌레의 수
// j = 0: 태어남
// j = 1: 성체가 됨
// j = 2: 번식을 중단함

const int MOD = 1000;
int trans[1000010][3], sum[1000010][3];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int a, b, d, n;
    std::cin >> a >> b >> d >> n;

    trans[0][0] = sum[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        // 성체
        if (i - a >= 0)
        {
            trans[i][1] = trans[i - a][0];
            sum[i][1] = (sum[i - 1][1] - (i >= b ? trans[i - b][0] : 0) + trans[i][1] + MOD) % MOD;
        }
        // 태어남
        trans[i][0] = sum[i][1];
        sum[i][0] = (sum[i - 1][0] - (i >= a ? trans[i - a][0] : 0) + trans[i][0] + MOD) % MOD;
        // 번식 중단
        if (i - b >= 0)
        {
            trans[i][2] = trans[i - b][0];
            sum[i][2] = (sum[i - 1][2] - (i >= d ? trans[i - d][0] : 0) + trans[i][2] + MOD) % MOD;
        }
    }
    std::cout << (sum[n][0] + sum[n][1] + sum[n][2]) % MOD << '\n';
}