
#include <bits/stdc++.h>

using namespace std;

const int MAX = 300;
const int INF = 987654321;
int n, m, k;
int dp[MAX + 1][MAX + 1]; //cnt[i][j] -> i�� ������� �����ϰ� �������� j�� �̿����� �� ���� �� �ִ� �ִ� �⳻�� ����    

int visited[MAX + 1][MAX + 1]; //dp[i][j]-> i->j�� ���� �ִ� �⳻�� ����
int maxScore(int loc, int cnt)
{
    if (cnt == m && loc!= n)
        return -INF;

    if (loc == n)
        return 0;

    int &result = dp[loc][cnt];
    if (result != -1)
        return result;

    result = 0;

    for (int i = loc + 1; i <= n; i++)
        if (visited[loc][i])
            result = max(result, visited[loc][i] + maxScore(i, cnt + 1));

    return result;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < b)
        {
            visited[a][b] = max(visited[a][b], c);
        }
    }
    memset(dp, -1, sizeof(dp));

    cout << maxScore(1,1) << '\n';

    return 0;
}
