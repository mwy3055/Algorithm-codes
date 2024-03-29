#include <bits/stdc++.h>
using namespace std;

struct coord
{
    int y, x;
    coord(int y, int x) : y(y), x(x) {}
    bool operator<(coord c) const
    {
        if (this->y == c.y)
            return this->x < c.x;
        return this->y < c.y;
    }
    bool operator==(coord c)
    {
        return this->y == c.y && this->x == c.x;
    }
};
struct node
{
    int cnt, from;
    coord c;
    node(int cnt, int from, coord c) : cnt(cnt), from(from), c(c) {}
    bool operator<(const node n) const
    {
        if (this->cnt == n.cnt)
            return this->c < n.c;
        return this->cnt < n.cnt;
    }
    bool operator>(const node n) const
    {
        return !(*this < n);
    }
};

int h, w;
char board[100][101];
int cnt[100][100][4];
vector<coord> laser;

bool isin(int y, int x)
{
    return 0 <= y && y < h && 0 <= x && x < w;
}
int bfs()
{
    int src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    priority_queue<node, vector<node>, greater<node>> pq;

    for (int i = 0; i < 4; i++)
    {
        pq.emplace(0, i, laser[0]);
        cnt[laser[0].y][laser[0].x][i] = 0;
    }
    while (!pq.empty())
    {
        auto top = pq.top();
        auto &count = top.cnt, &from = top.from;
        auto &c = top.c;
        pq.pop();

        if (c == laser[1])
            return count;
        for (int i = 0; i < 4; i++)
        {
            int nc = count, ny = c.y + src[i][0], nx = c.x + src[i][1];
            if (!isin(ny, nx) || board[ny][nx] == '*' || (from != i && from % 2 == i % 2)) // 반대 방향으로 가는 건 불가능
                continue;
            if (from != i)
                nc++;
            // 거울 개수를 셀 때, 어느 방향에서 왔는지까지 고려해야 함
            if (cnt[ny][nx][i] <= nc)
                continue;
            cnt[ny][nx][i] = nc;
            pq.push(node(nc, i, coord(ny, nx)));
        }
    }

    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> w >> h;
    for (int i = 0; i < h; i++)
    {
        cin >> board[i];
        for (int j = 0; j < w; j++)
        {
            if (board[i][j] == 'C')
                laser.push_back(coord(i, j));
        }
    }

    memset(cnt, 0x3f, sizeof(cnt));
    cout << bfs();
}