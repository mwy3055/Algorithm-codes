n = int(input())
dp = list(map(lambda n: 0, list(range(n+3))))
dp2 = dp[:]
dp[1] = 2
dp[2] = 7
dp[3] = 22
dp2[3] = 1
MOD = 1e9+7
for i in range(4, n+1):
    dp2[i] = int((dp2[i-1]+dp[i-3]) % MOD)
    dp[i] = int((dp[i-2]*3+dp[i-1]*2+dp2[i]*2) % MOD)
print(dp[n])