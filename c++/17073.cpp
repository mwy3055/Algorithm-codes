//2019 �������б� ��ǻ�Ͱ��а� ���α׷��� ������ȸ Open Contest B��
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, w;
    cin >> n >> w;
    adj = vector<vector<int>>(n + 1);
    water = vector<double>(n + 1, 0);
    visit = vector<bool>(n + 1, false);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int tcnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (adj[i].size() == 1)
            tcnt++;
    }

    cout << fixed;
    cout.precision(10);
    cout << (double)w / tcnt;
}