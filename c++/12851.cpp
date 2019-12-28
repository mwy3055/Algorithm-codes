#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int d[100001];
int dcount[100001]; // 최단경로의 수
bool visit[100001][3];

void push(queue<int> &q, int n, int type, int curtime)
{
    if (0 <= n && n <= 100000 && (!visit[n][type] || curtime + 1 <= d[n]))
    {
        visit[n][type] = true;
        q.push(n);
    }
}
void bfs(int &n, int &k)
{
    if (n == k)
    {
        d[k] = 0;
        dcount[k] = 1;
        return;
    }

    queue<int> q;
    int time = 0;

    visit[n][0] = visit[n][1] = visit[n][2] = true;
    q.push(n);
    while (!q.empty())
    {
        int siz = q.size();
        bool searched = false;
        while (siz--)
        {
            int top = q.front();
            q.pop();
            if (time < d[top])
            {
                d[top] = time;
                dcount[top] = 1;
            }
            else if (time == d[top])
            {
                dcount[top]++;
            }

            push(q, top - 1, 0, time);
            push(q, top + 1, 1, time);
            push(q, top * 2, 2, time);
        }
        time++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(d, 0x3f, sizeof(int) * 100001);

    int n, k;
    cin >> n >> k;

    bfs(n, k);
    cout << d[k] << '\n'
         << dcount[k];
}