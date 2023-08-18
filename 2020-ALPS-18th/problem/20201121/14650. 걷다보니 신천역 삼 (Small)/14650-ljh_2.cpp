#include <iostream>
using namespace std;
 
const int MAX = 9;
int main() {
    int n;
    int dp[MAX+1][3];
    
    cin >> n;
 
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        }
    }
 
    cout << dp[n][0] << endl;
}
