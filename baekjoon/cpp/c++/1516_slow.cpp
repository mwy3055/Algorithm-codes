#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int n, enter[501], need[501], complete[501];
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
    queue<pii> q; // index, time
    for (int i = 1; i <= n; i++)
        if (enter[i] == 0)
            q.push({i, 0});

    int time = 0;
    while (!q.empty())
    {
        time++;
        int siz = q.size();
        while (siz--)
        {
            auto top = q.front();
            q.pop();

            int &index = top.first, &t = top.second;
            if (++t == need[index])
            {
                complete[index] = time;
                for (auto &node : graph[index])
                {
                    if (--enter[node] == 0)
                    {
                        q.push({node, 0});
                    }
                }
            }
            else
            {
                q.push({index, t});
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