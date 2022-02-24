#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(1001, vector<int>());
int label[1001];

void init()
{
    memset(label, 0, sizeof(int) * 1001);
    for (auto &g : graph)
        g.clear();
}
int dfs(int cur)
{
    int &ret = label[cur];
    if (ret)
        return ret;
    int morder = 0, mcount = 0;
    for (auto &child : graph[cur])
    {
        int rtn = dfs(child);
        if (morder == rtn)
        {
            mcount++;
        }
        else if (morder < rtn)
        {
            morder = rtn;
            mcount = 1;
        }
    }
    if (mcount == 1)
        return ret = morder;
    else
        return ret = morder + 1;
}
void solve()
{
    init();

    int k, m, p;
    cin >> k >> m >> p;
    for (int i = 0; i < p; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    cout << k << ' ' << dfs(m) << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}