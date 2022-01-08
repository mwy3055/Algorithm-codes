#include <bits/stdc++.h>
using namespace std;

int dp[100001]; // previous 최단 위치 저장
bool visit[100001];

void push(queue<int> &q, int n, int &pr)
{
    if (0 <= n && n <= 100000 && !visit[n])
    {
        visit[n] = true;
        dp[n] = pr;
        q.push(n);
    }
}
int bfs(int &n, int &k, stack<int> &s)
{
    queue<int> q;
    int ans = 0;

    visit[n] = true;
    q.push(n);
    while (!q.empty())
    {
        int siz = q.size();
        bool searched = false;
        while (siz--)
        {
            int top = q.front();
            q.pop();
            if (top == k)
            {
                searched = true;
                break;
            }

            push(q, top - 1, top);
            push(q, top + 1, top);
            push(q, top * 2, top);
        }
        if (searched)
            break;
        ans++;
    }

    int track = k;
    while (track != n)
    {
        s.push(track);
        track = dp[track];
    }
    s.push(n);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(int) * 100001);

    int n, k;
    cin >> n >> k;

    stack<int> s;
    int ans = bfs(n, k, s);
    cout << ans << '\n';
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
}