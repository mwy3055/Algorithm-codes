#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int n, enter[501], need[501], complete[501], pr[501]; // pr: time for constructing prerequisite buildings of i-th
set<int> graph[501];

void getinput()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> need[i];
        int pre;
        cin >> pre;
        while (pre != -1)
        {
            graph[pre].insert(i);
            enter[i]++;
            cin >> pre;
        }
    }
}
void solve()
{
    // topology sort
    queue<int> q; // index
    for (int i = 1; i <= n; i++)
    {
        if (enter[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        // time = prerequisite + current
        complete[top] = pr[top] + need[top];
        for (auto &adj : graph[top])
        {
            pr[adj] = max(pr[adj], complete[top]);
            if (--enter[adj] == 0)
            {
                q.push(adj);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    getinput();
    solve();
    for (int i = 1; i <= n; i++)
        cout << complete[i] << '\n';
}