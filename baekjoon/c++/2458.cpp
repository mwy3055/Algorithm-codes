#include <bits/stdc++.h>
using namespace std;

int bfs(int &n, vector<int> *cmp, int cur)
{
    bool visit[n + 1] = {false};
    queue<int> q;
    int ans = 0;

    visit[cur] = true;
    q.push(cur);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        for (auto &larger : cmp[top])
        {
            if (!visit[larger])
            {
                visit[larger] = true;
                q.push(larger);
                ans++;
            }
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> lcmp[n + 1], scmp[n + 1], scount(n + 1, -1), lcount(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        lcmp[a].push_back(b);
        scmp[b].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int larger = bfs(n, lcmp, i), smaller = bfs(n, scmp, i);
        if (larger + smaller == n - 1)
            ans++;
    }
    cout << ans;
}