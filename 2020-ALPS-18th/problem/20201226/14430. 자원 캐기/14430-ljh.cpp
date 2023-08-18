#include <bits/stdc++.h>

using namespace std;

const int MAX = 300;

int n, m;
int board[MAX+1][MAX+1]; 
int dp[MAX+1][MAX+1]; // dp[i][j]-> (i,j) 칸 까지 최대 자원 탐색 개수  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    dp[0][0] = board[0][0];
    // dp[1][0] = board[0][0] + board[1][0];
    // dp[0][1] = board[0][0] + board[0][1];

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i == 0 && j == 0)
                continue;
            if (i == 0){
                dp[i][j] = dp[i][j-1] + board[i][j];
            }
            else if (j == 0){
                dp[i][j] = dp[i-1][j] + board[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + board[i][j];
            }
        }
    }
    //else의 중요성! 

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout <<'\n';
    // }

    cout << dp[n-1][m-1] << '\n';
    
    return 0;
}
