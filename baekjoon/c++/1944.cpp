#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Edge;                  // distance, index
typedef pair<int, int> Vertex;                // key, index
typedef pair<int, int> Coord;                 // {y, x}
typedef pair<int, Coord> Point;               // index, Coord
typedef pair<int, pair<int, int>> indir_edge; // dist, <index 1, index 2>
struct Search
{
    int dist, y, x;
    Search(int dist, int y, int x) : dist(dist), y(y), x(x) {}
};
int n, m, max_reach_count;
char maze[50][51];
int id[50][50];

Coord start;
vector<Point> points;
priority_queue<indir_edge, vector<indir_edge>, greater<indir_edge>> pq;

bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < n;
}
void bfs(Point &start)
{
    static int src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    bool visit[n][n] = {false};
    queue<Search> q;

    int &sidx = start.first, &sy = start.second.first, &sx = start.second.second;
    Search s(0, sy, sx);

    int tcnt = 0;
    visit[sy][sx] = true;
    q.push(s);
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        int &dist = top.dist, &y = top.y, &x = top.x;

        if ((maze[y][x] == 'S' || maze[y][x] == 'K') && sidx < id[y][x])
        {
            tcnt++;
            pq.push({dist, {sidx, id[y][x]}});
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = y + src[i][0], nx = x + src[i][1];
            if (isin(ny, nx) && maze[ny][nx] != '1' && !visit[ny][nx])
            {
                visit[ny][nx] = true;
                q.push(Search(dist + 1, ny, nx));
            }
        }
    }
    max_reach_count = max(max_reach_count, tcnt);
}
void preprocess()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (maze[i][j] == 'S' || maze[i][j] == 'K')
            {
                id[i][j] = cnt;
                points.push_back({cnt++, {i, j}});
            }
        }
    }

    for (int i = 0; i < points.size() - 1; i++)
        bfs(points[i]);
}

const int MAX = 251;
int root[MAX + 1];
void init()
{
    for (int i = 0; i <= MAX; i++)
        root[i] = -1;
}
int find(int n)
{
    if (root[n] < 0)
        return n;
    return root[n] = find(root[n]);
}
void union_vertex(int a, int b)
{
    int root1 = find(a), root2 = find(b);
    if (root1 == root2)
        return;

    if (root[root1] > root[root2])
        swap(root1, root2);

    root[root1] += root[root2];
    root[root2] = root1;
}

int solve()
{
    if (max_reach_count < m)
        return -1;

    int sum = 0;
    while (!pq.empty())
    {
        auto top = pq.top();
        int &dist = top.first, &a = top.second.first, &b = top.second.second;
        pq.pop();

        if (find(a) == find(b))
            continue;

        union_vertex(a, b);
        sum += dist;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> maze[i];

    preprocess();
    cout << solve();
}