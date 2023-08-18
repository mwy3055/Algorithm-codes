#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<int, int> coord; //y, x
typedef pair<int, coord> target;
bool operator==(coord a, coord b)
{
    return a.first == b.first && a.second == b.second;
}
struct shark
{
    coord c;
    int size, stack;
    shark(coord c, int size)
    {
        this->c = c;
        this->size = size;
        this->stack = 0;
    }
};
int n, map[20][20];
int src[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int debug[20][20];
bool visit[20][20];

bool isin(int &y, int &x)
{
    return 0 <= y && y < n && 0 <= x && x < n;
}
void Fill()
{
    for (int i = 0; i < n; i++)
        fill(visit[i], visit[i] + n, false);
}
int bfs(shark &b, int &y, int &x)
{
    Fill();
    queue<coord> q;
    coord dest = coord(y, x);

    q.push(b.c);
    visit[b.c.first][b.c.second] = true;
    int d = 0;
    while (!q.empty())
    {
        int siz = q.size();
        for (int a = 0; a < siz; a++)
        {
            coord &top = q.front();
            q.pop();
            if (top == dest)
                return d;
            for (int i = 0; i < 4; i++)
            {
                int sy = top.first + src[i][0], sx = top.second + src[i][1];
                if (isin(sy, sx) && !visit[sy][sx] && map[sy][sx] <= b.size)
                {
                    visit[sy][sx] = true;
                    q.push(coord(sy, sx));
                }
            }
        }
        d++;
    }
    return -1;
}

void find_target(shark &baby, vector<target> &v)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] != 0 && map[i][j] < baby.size)
            {
                int d = bfs(baby, i, j);
                if (d != -1)
                    v.push_back(target(d, coord(i, j)));
            }
        }
    }
}
bool eat(shark &baby, int &time)
{
    vector<target> v;
    find_target(baby, v);
    if (v.size() == 0)
        return false;

    sort(v.begin(), v.end());
    target &t = v[0];

    baby.c = t.second;
    baby.stack++;
    if (baby.stack == baby.size)
    {
        baby.stack = 0;
        baby.size++;
    }
    map[t.second.first][t.second.second] = 0;
    time = t.first;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    shark baby = shark(coord(0, 0), 2);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                baby.c = coord(i, j);
                map[i][j] = 0;
            }
        }
    }

    int cnt = 0, time;
    while (eat(baby, time))
        cnt += time;
    cout << cnt;
}