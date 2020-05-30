#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int INF = 0x3f3f3f3f;
    int d[51][51];
    for (int i = 0; i < 51; i++)
    {
        memset(d + i, 0x3f, sizeof(int) * 51);
        d[i][i] = 0;
    }

    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    while (a != -1 && b != -1)
    {
        d[a][b] = d[b][a] = 1;
        cin >> a >> b;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 1; i <= n; i++)
    {
        int score = 0;
        for (int j = 1; j <= n; j++)
            score = max(score, d[i][j]);
        pq.push(pii(score, i));
    }

    vector<int> ans;
    int minscore = pq.top().first;
    while (!pq.empty() && pq.top().first == minscore)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    cout << minscore << ' ' << ans.size() << '\n';
    for (auto &a : ans)
        cout << a << ' ';
}