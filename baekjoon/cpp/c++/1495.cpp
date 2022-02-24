#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int dp[100][1001];
int solve(int cur, int curv, int &n, int &m, vector<int> &v)
{
    if (cur == n)
        return curv;
    int &ret = dp[cur][curv];
    if (ret != INF)
        return ret;
    ret = -1;
    if (curv + v[cur] <= m)
        ret = solve(cur + 1, curv + v[cur], n, m, v);
    if (0 <= curv - v[cur])
        ret = max(ret, solve(cur + 1, curv - v[cur], n, m, v));
    return ret;
}
void init()
{
    for (int i = 0; i < 100; i++)
        memset(dp + i, INF, sizeof(int) * 1001);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    int n, s, m;
    vector<int> v(100);
    cin >> n >> s >> m;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int ans = solve(0, s, n, m, v);
    cout << ans;
}