#include <bits/stdc++.h>
using namespace std;

int n;
bool Map[100][100];
int islMap[100][100];

struct Coord
{
    int y, x;
    Coord(int y = 0, int x = 0) : y(y), x(x) {}

    Coord operator+(Coord c)
    {
        return Coord(this->y + c.y, this->x + c.x);
    }
    bool isin()
    {
        return (0 <= this->y && this->y < n) && (0 <= this->x && this->x < n);
    }
};

vector<Coord> faces = {Coord(1, 0), Coord(0, 1), Coord(-1, 0), Coord(0, -1)};

using Island = vector<Coord>;
using Islands = vector<Island>;

void find_bfs(Coord start, Island &isl, bool (*visit)[100], int &nth)
{
    queue<Coord> q;

    visit[start.y][start.x] = true;
    q.push(start);
    isl.push_back(start);
    islMap[start.y][start.x] = nth;

    while (!q.empty())
    {
        Coord top = q.front();
        q.pop();

        for (Coord &face : faces)
        {
            Coord next = top + face;

            if (next.isin() && Map[next.y][next.x] && !visit[next.y][next.x])
            {
                visit[next.y][next.x] = true;
                q.push(next);
                isl.push_back(next);
                islMap[next.y][next.x] = nth;
            }
        }
    }
}
void find_islands(Islands &islands)
{
    bool visit[100][100] = {false};

    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (Map[i][j] && !visit[i][j])
            {
                Island t = Island();
                find_bfs(Coord(i, j), t, visit, cnt);
                islands.push_back(t);
                cnt++;
            }
        }
    }
}

bool is_another_island(Coord &src, Coord &dst)
{
    return dst.isin() && Map[dst.y][dst.x] && islMap[dst.y][dst.x] && islMap[dst.y][dst.x] != islMap[src.y][src.x];
}
int min_dist(Island &isl)
{
    Coord &ref = isl[0];
    bool visit[100][100] = {false};
    queue<Coord> q;

    //큐 초기화: 섬의 좌표를 전부 넣음
    for (auto &i : isl)
    {
        visit[i.y][i.x] = true;
        q.push(i);
    }

    for (int count = 0; !q.empty(); count++)
    {
        int siz = q.size();
        while (siz--)
        {
            Coord top = q.front();
            q.pop();

            for (auto &face : faces)
            {
                Coord next = top + face;
                if (is_another_island(ref, next))
                {
                    return count;
                }

                if (next.isin() && !Map[next.y][next.x] && !visit[next.y][next.x])
                {
                    visit[next.y][next.x] = true;
                    q.push(next);
                }
            }
        }
    }
    return 1e9;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> Map[i][j];

    Islands islands;
    find_islands(islands);

    int ans = 1e9;
    for (auto &v : islands)
        ans = min(ans, min_dist(v));

    cout << ans;
}