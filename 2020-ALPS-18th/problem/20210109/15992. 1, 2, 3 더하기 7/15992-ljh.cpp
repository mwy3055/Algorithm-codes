//아 씨팔 또 long long으로 한번 틀려버림

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

long long dp[MAX + 1][MAX +1][4]; // dp[i][j][k] -> 첫번째로 오는 수가 k일때 1,2,3의 합으로 정수 i을 j개의 수로 만드는 경우의 수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc, n, m;

    cin >> tc;

    //기저조건

    dp[1][1][1] = 1; //1
    dp[2][1][2] = 1; //2
    //dp[2][2][1] = 1; //1+1
    dp[3][1][3] = 1; //3
    dp[3][2][1] = 1; //1+2
    dp[3][2][2] = 1; //2+1
    //dp[3][3][1] = 1; //1+1+!

    for(int i = 1; i < MAX+1; i++){
        dp[i][i][1] = 1;
    }

    for (int i = 4; i < MAX+1; i++){
        for(int j = 2; j < MAX+1; j++){
            dp[i][j][1] = (dp[i-1][j-1][1] + dp[i-1][j-1][2] + dp[i-1][j-1][3])%1000000009;
            dp[i][j][2] = (dp[i-2][j-1][1] + dp[i-2][j-1][2] + dp[i-2][j-1][3])%1000000009;
            dp[i][j][3] = (dp[i-3][j-1][1] + dp[i-3][j-1][2] + dp[i-3][j-1][3])%1000000009;
        }
    }
    while (tc--)
    {
        cin >> n >> m;

        long long ans = (dp[n][m][1] + dp[n][m][2] + dp[n][m][3]) % 1000000009;

        cout << ans << '\n';

    }

    return 0;
}

