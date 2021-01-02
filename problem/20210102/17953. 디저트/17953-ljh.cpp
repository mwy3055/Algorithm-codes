
#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[11][100001];
int dp[11][100001]; //dp[i][j] = i번째 디저트를, j번째 날에 먹었을때, 만족감의 최대값
 
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    //기저 조건
    for (int i = 1; i <= m; i++){
        dp[i][n] = arr[i][n];

        cout << dp[i][n] << '\n';
    }

    //문제의 지점 
    for (int j = n-1; j >= 1; j--)
    {
        for(int i = 1; i <= m; i++){
            int max_cnt = -1;
            for(int k = 1; k <= m; k++){
                if (k == i) max_cnt = max(max_cnt, (dp[i][j+1])/2);
                //다음에 같은 디저트를 선택할 때
                else max_cnt = max(max_cnt, dp[k][j+1]);
                //다음에 다른 디저트를 선택할 때 
            }
            dp[i][j] = max_cnt + arr[i][j];
        }
    }

    int max_result = -1;

    //처음 선택에 따른 결과 중 최댓값을 출력 
    for(int i = 1; i <= m; i++){
        cout << dp[i][1] << '\n';
        max_result = max(max_result, dp[i][1]);
    }

    cout << max_result << '\n';

    return 0;
}
