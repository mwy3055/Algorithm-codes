#include <bits/stdc++.h>
using namespace std;

int solve(int &n, int *need, int *in, vector<set<int>> &graph)
{
    int tick = 0;
    bool inserted[n + 1] = {false};
    map<int, int> executing;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            inserted[i] = true;
            executing[i] = 0;
        }
    }

    while (!executing.empty())
    {
        tick++;
        set<int> push, erase;
        for (auto &cur : executing)
        {
            int cidx = cur.first;
            if (++cur.second == need[cidx])
            {
                erase.insert(cidx);
                for (auto next : graph[cidx])
                {
                    if (--in[next] == 0 && !inserted[next])
                    {
                        inserted[next] = true;
                        push.insert(next);
                    }
                }
            }
        }

        for (auto &e : erase)
            executing.erase(e);
        for (auto &p : push)
            executing[p] = 0;
    }
    return tick;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int need[n + 1], in[n + 1] = {0};
    vector<set<int>> graph(n + 1, set<int>());
    for (int i = 1; i <= n; i++)
    {
        cin >> need[i] >> in[i];
        for (int j = 0; j < in[i]; j++)
        {
            int c;
            cin >> c;
            graph[c].insert(i);
        }
    }

    cout << solve(n, need, in, graph);
}