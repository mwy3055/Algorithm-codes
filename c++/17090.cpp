#include <iostream>
#include <vector>
using namespace std;

class Coord
{
public:
    int y, x;
    Coord(int y = 0, int x = 0) : y(y), x(x) {}
    void operator+=(Coord c)
    {
        this->y += c.y;
        this->x += c.x;
    }
    Coord operator+(Coord c)
    {
        return Coord(this->y + c.y, this->x + c.x);
    }
};

int n, m;
char maze[500][500], can_escape[500][500];

inline Coord getmaze(const Coord &c)
{
    char cur = maze[c.y][c.x];
    switch (cur)
    {
    case 'U':
        return Coord(-1, 0);
    case 'D':
        return Coord(1, 0);
    case 'L':
        return Coord(0, -1);
    default:
        return Coord(0, 1);
    }
}
inline bool isin(const Coord &c)
{
    return 0 <= c.y && c.y < n && 0 <= c.x && c.x < m;
}
char escape(Coord c, vector<vector<bool>> &isvisit)
{
    if (!isin(c))
        return 1;

    char &esc = can_escape[c.y][c.x];
    if (esc)
        return esc;
    if (isvisit[c.y][c.x])
        return esc = 2;

    isvisit[c.y][c.x] = true;
    return can_escape[c.y][c.x] = escape(c + getmaze(c), isvisit);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> maze[i];

    int ans = 0;
    vector<vector<bool>> isvisit = vector<vector<bool>>(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (escape(Coord(i, j), isvisit) == 1)
                ans++;
        }
    }

    cout << ans;
}