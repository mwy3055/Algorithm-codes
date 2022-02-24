#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Coord;

int r, c, src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char board[1500][1501];
bool cvisit[1500][1500], mvisit[1500][1500];
vector<Coord> s;
list<Coord> ices;
queue<Coord> swan, ice, temp;

bool isin(int y, int x)
{
    return 0 <= y && y < r && 0 <= x && x < c;
}

bool check() // whether two swans can meet
{
    while (!swan.empty())
    {
        auto top = swan.front();
        swan.pop();

        if (top == s[1])
            return true;
        auto &y = top.first, &x = top.second;
        for (int i = 0; i < 4; i++)
        {
            int sy = y + src[i][0], sx = x + src[i][1];
            if (isin(sy, sx) && !cvisit[sy][sx] && board[sy][sx] == '.')
            {
                swan.push(Coord(sy, sx));
                cvisit[sy][sx] = true;
            }
            if (isin(sy, sx) && !cvisit[sy][sx] && board[sy][sx] == 'X')
            {
                temp.push(Coord(sy, sx));
                cvisit[sy][sx] = true;
            }
        }
    }
    swan = temp;
    while (!temp.empty())
        temp.pop();
    return false;
}

void initialize() // find out-est ice
{
    for (auto &cur : ices)
    {
        auto &y = cur.first, &x = cur.second;
        for (int i = 0; i < 4; i++)
        {
            int ny = y + src[i][0], nx = x + src[i][1];
            if (isin(ny, nx) && board[ny][nx] != 'X')
            {
                ice.push(Coord(y, x));
                mvisit[y][x] = true;
                break;
            }
        }
    }
}
void melt()
{
    int siz = ice.size();
    while (siz--)
    {
        auto top = ice.front();
        auto &y = top.first, &x = top.second;
        ice.pop();

        board[y][x] = '.';
        for (int i = 0; i < 4; i++)
        {
            int ny = y + src[i][0], nx = x + src[i][1];
            if (isin(ny, nx) && board[ny][nx] == 'X' && !mvisit[ny][nx])
            {
                ice.push(Coord(ny, nx));
                mvisit[ny][nx] = true;
            }
        }
    }
}

int solve()
{
    swan.push(s[0]);
    cvisit[s[0].first][s[0].second] = true;
    initialize();

    int ans = 0;
    while (!check())
    {
        melt();
        ans++;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        cin >> board[i];
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == 'L')
            {
                s.push_back(Coord(i, j));
                board[i][j] = '.';
            }
            else if (board[i][j] == 'X')
                ices.push_back(Coord(i, j));
        }
    }

    cout << solve() << '\n';
}