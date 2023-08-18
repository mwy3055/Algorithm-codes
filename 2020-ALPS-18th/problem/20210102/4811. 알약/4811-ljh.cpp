// 으악 문제를 잘못읽어서 시간날렸다. 한개를 쪼개먹고 나서 부터 시작이다...


#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[31][31]; //알약 i개, 반개짜리 알약 j개 일때 문자열의 총 경우의 수  

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int h = 0; h <= 30; h++){
        dp[0][h] = 1;
        //모두 반쪽짜리 알약이면 경우의수는 1개씩
    }

    for(int w = 1; w <= 30; w++){
        for(int h = 0; h <= 30; h++){
            if(h == 0){
                dp[w][h] = dp[w-1][1];
                //반쪽짜리 알약이 없으면 큰 알약을 쪼개먹고 작은 알약 하나를 만듬
            }
            else{
                dp[w][h] = dp[w-1][h+1] + dp[w][h-1];
                //큰 알약을 쪼개 먹고 반쪽짜리 알약을 만드는 경우 + 반쪽 짜리 알약을 먹는 경우 
            }
        }
    }


    while(true){
        cin >> n;

        if(n == 0)
            break;
        else{
            cout << dp[n-1][1] << '\n';
        }
        
    }

    return 0;
}
