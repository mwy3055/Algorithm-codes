#include <bits/stdc++.h>

const int MAX = 100;
const int INF = 0x3f3f3f3f;

using namespace std;

int n, m;
int cost[MAX + 1][MAX + 1];
int route[MAX + 1][MAX + 1];

vector<int> v;

void floyd_warshall()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                if (cost[i][j] > cost[i][k] + cost[k][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                    route[i][j] = k;
                }
            }
        }
    }
}

void find_route(int start, int end)
{
    if (route[start][end] == 0)
    {
        v.push_back(start);
        v.push_back(end);

        return;
    }
    find_route(start, route[start][end]);
    v.pop_back();
    find_route(route[start][end], end);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cost[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], c);
        //같은 경로에 더 비용이 많이 드는 경로가 뒤에 인풋으로 오는 경우가 있음!
        //floyd warshall이 문제가 있는게 아니라 경로 입력에 문제가 있던 것!
    }

    floyd_warshall();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cost[i][j] == INF)
                cout << 0 << " ";
            else
                cout << cost[i][j] << " ";
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cost[i][j] == INF)
                cout << 0;
            else
            {
                v.clear();
                find_route(i, j);
                cout << v.size() << " ";
                for (int k = 0; k < v.size(); k++)
                    cout << v[k] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}