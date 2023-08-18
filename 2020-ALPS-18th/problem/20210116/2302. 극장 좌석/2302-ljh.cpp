
//시팔 예외처리 넘 빡시다 
//모든 좌석이 고정석알때를 고려하지 않음! 
//dp[0]을 저장하지 않음 (고정석이 붙어있을 때) -> 위의 경우의 수를 포함함

#include <bits/stdc++.h>

using namespace std;

const int MAX = 40;

int n, m;

int dp[MAX + 1]; //고정석 없이 1~i를 배치하는 경우의 수

vector<int> cases;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> m;

    vector<int> vip(m+1);

    for (int i = 1; i <= m; i++)
    {
        // int tmp;
        // cin >> tmp;
        // vip.push_back(tmp);
        cin >> vip[i];
    }


    dp[0] = 1;

    dp[1] = 1;
    dp[2] = 2; // 서로 자리 바꿔앉기
               // d[3] = 3;
               // d[4] = 5;
               // d[5] = 8; // -> d[n] = d[n-1] + d[n-2] (단, n > 2)
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // if (n == m){

    //     cout << '1' << '\n';

    //     return 0;
    // }

    //고정석이 없을 때 
    else if (m == 0)
    {
        cout << dp[n] << '\n';

        return 0;
    }

    else
    {
        int num = 1;

        //첫번째 좌석부터 첫번째 고정석 사이 경우의 수
        cases.push_back(dp[vip[1] - 1]);

        //n번째 고정석부터 n+번째 고정석 사이의 경우의 수
        while (num < m)
        {
            cases.push_back(dp[vip[num + 1] - vip[num] - 1]);
            num++;
        }

        //마지막 고정석부터 마지막 좌석 사이의 경우의 수
        cases.push_back(dp[n - vip[m]]);

        int result = 1;

        //고정석을 어떠한 축으로 보았을때 모든 경우의수는 기둥으로 구분된 구간의 경우의수의 곱과 같음

        for (auto &j : cases)
        {
            //경우의수 잘 세지나 확인 
            // cout << j << '\n';
            result *= j;
        }

        cout << result << '\n';

        return 0;
    }
}
