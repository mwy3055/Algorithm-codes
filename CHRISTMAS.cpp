#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int subsum[100001], cnt[100001], dp[100001], ploc[100001];
/*
    상자의 번호는 1부터 시작한다.
    
    subsum[i] = [1, i] 구간의 합 mod K
    cnt[i] = subsum 배열에서 i의 개수
    dp[i] = [1, i] 구간에서 구매할 수 있는 구간의 최댓값
    ploc[i] = [1, i) 구간에서 i가 등장한 가장 나중 위치
 */
void init(int n, int k)
{
    memset(subsum, 0, (n + 1) * sizeof(int));
    memset(cnt, 0, k * sizeof(int));
    memset(dp, 0, (n + 1) * sizeof(int));
    memset(ploc, -1, (k + 1) * sizeof(int));
}

int solve1(int &n, int &k)
{
    static int MOD = 20091101;
    ll ans = 0;
    for (int i = 0; i < k; i++)
        ans = (ans + ((ll)cnt[i] * (cnt[i] - 1) / 2)) % MOD;

    return ans;
}

int solve2(int i, int n) //[1, i] 구간에서. (1<=i<=n)
{
    for (int i = 0; i <= n; i++)
    {
        dp[i] = ((i == 0) ? 0 : dp[i - 1]);

        int prevloc = ploc[subsum[i]];
        if (prevloc != -1)
            dp[i] = max(dp[i], dp[prevloc] + 1);
        ploc[subsum[i]] = i;
    }
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k, temp;
        cin >> n >> k;
        init(n, k);
        for (int i = 1; i <= n; i++)
        {
            cin >> temp;
            subsum[i] = (subsum[i - 1] + temp) % k;
            cnt[subsum[i]]++;
        }
        cnt[0]++;

        cout << solve1(n, k) << ' ' << solve2(1, n) << '\n';
    }
}