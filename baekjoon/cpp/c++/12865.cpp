#include <bits/stdc++.h>
using namespace std;

struct object
{
    int w, v;
};

int dp[100][100001] = {0}; // dp[i][j]: i번째 물건을 (선택 또는 선택하지 않은 후의) 무게가 j일 때의 최대 만족감

int solve(int &n, int &k, vector<object> &objs)
{
    dp[0][objs[0].w] = objs[0].v;
    for (int i = 1; i < n; i++) //i번째 물건을 넣을까 말까..
    {
        for (int j = 0; j <= k; j++)
        {
            if (j - objs[i].w >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - objs[i].w] + objs[i].v);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int ans = 0;
    for (int j = 1; j <= k; j++)
        ans = max(ans, dp[n - 1][j]);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<object> objs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> objs[i].w >> objs[i].v;
    }

    cout << solve(n, k, objs);
}