#include <iostream>
#include <queue>
using namespace std;

int src[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1}; //»óÇÏÁÂ¿ì
struct coord
{
    int y, x, dir;
    char c;
    bool operator==(const coord t)
    {
        return this->y == t.y && this->x == t.x;
    }
    coord operator+(const int i)
    {
        return coord{this->y + src[i][0], this->x + src[i][1], this->dir, this->c};
    }
    void operator+=(const int i)
    {

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
                return coord{i, j, -1, c};
            }
        }
    }
    return coord{0, 0, -1, c};
}

void sameline(int dir, coord &s, coord &t, coord &front, coord &back)
{
    //»óÇÏÁÂ¿ì
    if (dir == 0 && s.x == t.x)
    {
        if (s.y < t.y)
        {
            front = s;
            back = t;
        }
        else
        {
            front = t;
            back = s;
        }
    }
    else if (dir == 1 && s.x == t.x)
    {
        if (s.y < t.y)
        {
            front = t;
            back = s;
        }
        else
        {
            front = s;
            back = t;
        }
    }
    else if (dir == 2 && s.y == t.y)
    {
        if (s.x < t.x)
        {
            front = s;
            back = t;
        }
        else
        {
            front = t;
            back = s;
        }
    }
    else if (dir == 3 && s.y == t.y)
    {
        if (s.x < t.x)
        {
            front = t;
            back = s;
        }
        else
        {
            front = s;
            back = t;
        }
    }
}
bool roll(queue<coord> &q, int dir, coord c, coord &HOLE)
{
    if (c.dir == dir)
        return false;

    while (get(c + dir) != '#')
    {
        c += dir;
        if (c.c == 'R' && c == HOLE)
            return true;
    }
    c.dir = dir;
    q.push(c);
    return false;
}

int bfs(int &n, int &m)
{
    coord R = Find('R'), B = Find('B'), HOLE = Find('O');
    map[R.y][R.x] = map[B.y][B.x] = '.';

    queue<coord> q;
    q.push(R);
    q.push(B);
    int rtn = 0;
    while (!q.empty())
    {
        int siz = q.size() / 2;
        rtn++;
        for (int a = 0; a < siz; a++)
        {
            coord first = q.front();
            q.pop();
            coord second = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) //»óÇÏÁÂ¿ì
            {
                coord front = first, back = second;
                sameline(dir, front, back, front, back);

                if (roll(q, dir, front, HOLE))
                    return rtn;
                if (roll(q, dir, back, HOLE))
                    return rtn;
            }
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