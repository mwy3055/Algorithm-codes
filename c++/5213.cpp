#include <bits/stdc++.h>
using namespace std;

int n, board[500][1000], tileno[500][1000], track[250000], maxtno, src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
bool visit[250000];
vector<vector<int>> adj;

bool issame(int y1, int x1, int y2, int x2)
{
    return tileno[y1][x1] == tileno[y2][x2];
}
bool isin(int y, int x)
{
    if (y < 0 || y >= n)
        return false;
    if (y % 2)
        return 0 < x && x < 2 * n - 1;
    return 0 <= x && x < 2 * n;
}
void solve()
{
    queue<int> q;
    int maxtno = 0;

    q.push(1);
    visit[1] = true;
    while (!q.empty())
    {
        int siz = q.size();
        while (siz--)
        {
            auto top = q.front();
            q.pop();

            maxtno = max(maxtno, top);
            for (auto &node : adj[top])
            {
                if (!visit[node])
                {
                    q.push(node);
                    visit[node] = true;
                    track[node] = top;
                }
            }
        }
    }

    int cur = maxtno;
    stack<int> s;
    do
    {
        s.push(cur);
        cur = track[cur];
    } while (cur != 1);
    s.push(1);

    cout << s.size() << '\n';
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';
}

void getinput()
{
    int tcount = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int end = (i % 2 ? n - 1 : n), offset = i % 2;
        for (int j = 0; j < end; j++)
        {
            int a, b;
            cin >> a >> b;
            board[i][offset + j * 2] = a;
            board[i][offset + j * 2 + 1] = b;
            tileno[i][offset + j * 2] = tileno[i][offset + j * 2 + 1] = tcount;
            tcount++;
        }
    }
    maxtno = tcount - 1;

    adj.resize(maxtno + 1);
    for (int i = 0; i < n; i++)
    {
        int end = (i % 2 ? n - 1 : n), offset = i % 2;
        for (int j = 0; j < end; j++)
        {
            int cy = i;
            for (int k = 0; k < 2; k++)
            {
                int cx = offset + j * 2 + k;
                for (int a = 0; a < 4; a++)
                {
                    int ny = cy + src[a][0], nx = cx + src[a][1];
                    if (isin(ny, nx) && !issame(cy, cx, ny, nx) && board[cy][cx] == board[ny][nx])
                    {
                        adj[tileno[ny][nx]].push_back(tileno[cy][cx]);
                    }
                }
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
}