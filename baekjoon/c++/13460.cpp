#include <iostream>
#include <queue>
using namespace std;

int src[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1}; //상하좌우
struct coord
{
    int y, x, dir;
    char c;
    bool operator==(const coord t)
    {
        return this->y == t.y && this->x == t.x;
    }
    bool operator!=(const coord t)
    {
        return !(this->y == t.y && this->x == t.x);
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

char map[10][11];
char &get(const coord &c)
{
	if (c.y < 0 || c.x < 0)
		return map[0][0];
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

void sameline(int dir, coord s, coord t, coord &front, coord &back)
{
    //상하좌우
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
bool roll(queue<coord> &q, int dir, coord& f, coord& s, coord &HOLE)
{
	coord &R = (f.c == 'R' ? f : s), &B = (f.c == 'B' ? f : s);
	coord bf = f, bs = s;
	bool hr = false, hb = false;
	while (true)
	{
		if (get(f + dir) == '#' && (get(s + dir) == '#' || s + dir == f)) //둘 다 움직일 수 없을 때
			break;
		if (get(f + dir) != '#')
			f += dir;
		if (get(s + dir) != '#' && s + dir != f)
			s += dir;
		if ((f.c == 'R' && f == HOLE) || (s.c == 'R' && s == HOLE))
		{
			hr = true;
			R.x = R.y = -1;
		}
		if ((f.c == 'B' && f == HOLE) || (s.c == 'B' && s == HOLE))
		{
			hb = true;
			B.x = B.y = -1;
		}
	}
	if ((f != bf || s != bs) && !hb) //둘 중 하나라도 변했으면
	{
		q.push(f);
		q.push(s);
	}
	return hr && !hb;
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
		if (10 < rtn)
			return -1;
		for (int a = 0; a < siz; a++)
		{
			coord first = q.front();
			q.pop();
			coord second = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++) //상하좌우
			{
				coord f = first, s = second;
				sameline(dir, f, s, f, s);

				if (roll(q, dir, f, s, HOLE))
					return rtn;
			}
		}
	}
	return -1;
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