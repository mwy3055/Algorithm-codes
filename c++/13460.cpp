#include <iostream>
#include <queue>
using namespace std;

struct coord
{
    int y, x;
    bool operator==(const coord t)
    {
        return this->y == t.y && this->x == t.x;
    }
    void operator+=(const int i)
    {
        static int src[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
        this->y += src[i][0];
        this->x += src[i][1];
    }
};

char map[10][10];
char &get(const coord &c)
{
    return map[c.y][c.x];
}
coord Find(char c)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j] == c)
            {
                return coord{i, j};
            }
        }
    }
    return coord{0, 0};
}

int bfs(int &n, int &m)
{
    coord R = Find('R'), B = Find('B'), HOLE = Find('O');

    queue<coord> q; //항상 r, b 좌표가 쌍으로 들어있음
    q.push(R);
    q.push(B);
    int rtn = 0;
    while (!q.empty())
    {
        coord &r = q.front();
        q.pop();
        coord &b = q.front();
        q.pop();
        rtn++;

        for (int dir = 0; dir < 4; dir++) //상하좌우
        {
            coord tr = r, tb = b;
            //두 구슬이 같은 방향에 있다면: 굴릴 때 처리..
/*            while (get(tr + dir) == '.')
            {
                tr += dir;
                if (tr == HOLE)
                    return rtn;
            }*/
        }
    }
    return rtn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> map[i];

    cout << bfs(n, m);
}