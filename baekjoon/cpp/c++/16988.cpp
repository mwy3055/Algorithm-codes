#include <bits/stdc++.h>
using namespace std;

int n, m, Map[20][20];
int src[][2] = {1, 0, -1, 0, 0, 1, 0, -1};

class Coord
{
public:
    int y, x;
    Coord(int y = 0, int x = 0) : y(y), x(x) {}
    static bool isin(int y, int x)
    {
        return 0 <= y && y < n && 0 <= x && x < m;
    }
};

template <typename T>
using dvector = vector<vector<T>>;

void bfs(int &y, int &x, dvector<Coord> &groups, dvector<bool> &visit)
{
    queue<Coord> q;

    groups.push_back(vector<Coord>());
    int siz = groups.size();

    q.push(Coord(y, x));
    visit[y][x] = true;
    while (!q.empty())
    {
        Coord top = q.front();
        groups[siz - 1].push_back(top);
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int sy = top.y + src[i][0], sx = top.x + src[i][1];
            if (Coord::isin(sy, sx) && Map[sy][sx] == 2 && !visit[sy][sx])
            {
                visit[sy][sx] = true;
                q.push(Coord(sy, sx));
            }
        }
    }
}
void makegroup(dvector<Coord> &groups)
{
    dvector<bool> visit(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Map[i][j] == 2 && !visit[i][j])
            {
                bfs(i, j, groups, visit);
            }
        }
    }
}

bool issiegedstone(Coord &c)
{
    for (int i = 0; i < 4; i++)
    {
        int sy = c.y + src[i][0], sx = c.x + src[i][1];
        if (Coord::isin(sy, sx) && Map[sy][sx] == 0)
            return false;
    }
    return true;
}
bool issiegedgroup(vector<Coord> &group)
{
    for (Coord &c : group)
    {
        if (!issiegedstone(c))
            return false;
    }
    return true;
}
int countkill(dvector<Coord> &groups)
{
    int cnt = 0;
    for (vector<Coord> &group : groups)
    {
        if (issiegedgroup(group))
            cnt += group.size();
    }
    return cnt;
}
int solve(dvector<Coord> &groups)
{
    int ans = 0;
    for (int y1 = 0; y1 < n; y1++)
    {
        for (int x1 = 0; x1 < m; x1++)
        {
            if (Map[y1][x1])
                continue;
            for (int y2 = y1; y2 < n; y2++)
            {
                for (int x2 = (y2 == y1 ? x1 + 1 : 0); x2 < m; x2++)
                {
                    if (Map[y2][x2])
                        continue;

                    Map[y1][x1] = Map[y2][x2] = 1;
                    int rtn = countkill(groups);
                    ans = max(ans, rtn);
                    Map[y1][x1] = Map[y2][x2] = 0;
                }
            }
        }
    }
    return ans;
}

/* for debug */
void printgroup(dvector<Coord> &groups)
{
    for (vector<Coord> &group : groups)
    {
        cout << "========================\n";
        for (Coord &c : group)
        {
            cout << c.y << " " << c.x << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> Map[i][j];

    dvector<Coord> groups;
    makegroup(groups);

    printgroup(groups);

    cout << solve(groups);
}