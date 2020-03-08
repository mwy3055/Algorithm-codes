#include <bits/stdc++.h>
using namespace std;

struct pole
{
    int idx, x, y;
};
vector<vector<int>> graph(50001, vector<int>());

bool cmp(const pole &a, const pole &b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
void makegraph(int &n, vector<pole> &poles)
{
    sort(poles.begin(), poles.end(), cmp);
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (abs(poles[i].x - poles[j].x) <= 2 && abs(poles[i].y - poles[j].y) <= 2)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
            else if (abs(poles[i].x - poles[j].x) > 2 && abs(poles[i].y - poles[j].y) > 2)
                break;
        }
    }
}
int solve(int &n, int &t, vector<pole> &poles)
{
    queue<int> q;
    bool visit[n + 1] = {false};

    int cnt = 0;
    q.push(0);
    visit[0] = true;
    while (!q.empty())
    {
        int siz = q.size();
        while (siz--)
        {
            int top = q.front();
            q.pop();
            if (poles[top].y == t)
                return cnt;

            for (auto &adj : graph[top])
            {
                if (!visit[adj])
                {
                    q.push(adj);
                    visit[adj] = true;
                }
            }
        }
        cnt++;
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    vector<pole> poles(n + 1);
    poles[0] = {0, 0, 0};
    for (int i = 1; i <= n; i++)
    {
        poles[i].idx = i;
        cin >> poles[i].x >> poles[i].y;
    }

    makegraph(n, poles);
    cout << solve(n, t, poles);
}