#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
int pipe[201][201], n, k;

bool isin(int y, int x)
{
    return 0 < y && y <= n && 0 < x && x <= n;
}
int solve(priority_queue<pipii, vector<pipii>, greater<pipii>> &virus, int &s, int &x, int &y)
{
    int d[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    for (int t = 0; t < s; t++)
    {
        priority_queue<pipii, vector<pipii>, greater<pipii>> temp;
        while (!virus.empty())
        {
            auto top = virus.top();
            virus.pop();
            int type = top.first, r = top.second.first, c = top.second.second;
            for (int i = 0; i < 4; i++)
            {
                int cr = r + d[i][0], cc = c + d[i][1];
                if (isin(cr, cc) && !pipe[cr][cc])
                {
                    pipe[cr][cc] = type;
                    temp.push({type, {cr, cc}});
                }
            }
        }
        virus = temp;
    }
    return pipe[x][y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<pipii, vector<pipii>, greater<pipii>> virus;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> pipe[i][j];
            if (pipe[i][j])
            {
                virus.push({pipe[i][j], {i, j}});
            }
        }
    }

    int s, x, y;
    cin >> s >> x >> y;
    cout << solve(virus, s, x, y);
}