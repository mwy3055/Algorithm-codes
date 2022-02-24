#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> color(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //방문하지 않은 모든 정점에 대해 bfs
    queue<int> q;
    vector<bool> visit(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            color[i] = 0;
            visit[i] = true;
            q.push(i);
            while (!q.empty())
            {
                int &top = q.front();
                q.pop();

                int paint = 1 - color[top];
                for (int &node : adj[top])
                {
                    if (color[node] == color[top])
                        return false;
                    if (!visit[node])
                    {
                        color[node] = paint;
                        visit[node] = true;
                        q.push(node);
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cout << (solve() ? "possible" : "impossible") << '\n';
    }
}