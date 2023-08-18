
#include <bits/stdc++.h>

using namespace std;

int n, m;

using ll = long long;
const ll MOD = 1e9 + 7;

// long long mul[MAX+1];
// long long dp[MAX+1];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    //메모리를 좀 아껴보자 
    vector<ll> mul(n), dp(n);

    for(int i = 1; i < n; i++){
        cin >> mul[i];
    }

    dp[1] = mul[1];

    for(int i = 2; i < n; i++){
        dp[i] = (mul[i]*dp[i-1]%MOD + mul[i])%MOD; 
    } 

    ll sum = 0;

    for(int i = 1; i < n; i++){
        sum = (sum + dp[i])%MOD;
    }

    cout << sum << '\n';

    return 0;
}
