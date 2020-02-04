#include <bits/stdc++.h>
using namespace std;
int d[][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

int r, c, t;
int room[50][50];
int airtopy = -1, airtopx = -1, airbottomy = -1, airbottomx = -1;

void getinput()
{
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> room[i][j];
            if (room[i][j] == -1)
            {
                if (airtopy == -1)
                    airtopy = i, airtopx = j;
                else
                    airbottomy = i, airbottomx = j;
            }
        }
    }
}

bool isin(int y, int x)
{
    return 0 <= y && y < r && 0 <= x && x < c;
}
void spread()
{

    vector<vector<int>> spread(r, vector<int>(c, 0));
    for (int y = 0; y < r; y++)
    {
        for (int x = 0; x < c; x++)
        {
            int spreaded = 0;
            for (int i = 0; i < 4; i++)
            {
                int sy = y + d[i][0], sx = x + d[i][1];
                if (!isin(sy, sx) || room[sy][sx] == -1)
                    continue;

                spread[sy][sx] += room[y][x] / 5;
                spreaded += room[y][x] / 5;
            }
            room[y][x] -= spreaded;
        }
    }

    for (int y = 0; y < r; y++)
        for (int x = 0; x < c; x++)
            room[y][x] += spread[y][x];
}

void circle(int *dir, int cy, int cx, int airy)
{
    // 바람 방향의 반대로 가면서, 앞 칸 미세먼지를 끌어당김
    while (true)
    {
        int sy = cy + d[*dir][0], sx = cx + d[*dir][1];
        if (!isin(sy, sx) || (cy == airy && cx == c - 1))
        {
            dir++;
            sy = cy + d[*dir][0], sx = cx + d[*dir][1];
        }
        if (room[sy][sx] == -1)
        {
            room[cy][cx] = 0;
            break;
        }
        if (room[cy][cx] != -1)
            room[cy][cx] = room[sy][sx];

        cy = sy;
        cx = sx;
    }
}
void wind()
{
    int dir1[] = {0, 2, 1, 3}, dir2[] = {1, 2, 0, 3};

    circle(dir1, airtopy, airtopx, airtopy);
    circle(dir2, airbottomy, airbottomx, airbottomy);
}

int answer()
{
    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (room[i][j] != -1)
                ans += room[i][j];
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    getinput();

    for (int i = 0; i < t; i++)
    {
        spread();
        wind();
    }

    cout << answer();
}