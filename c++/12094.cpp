#include <iostream>
#include <string.h>
using namespace std;

const int MAXDEP = 10;
int ans, n;
int map[20][20];

void up()
{
    bool doubled[20][20] = {false};
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 0)
                continue;
            int val = map[i][j], ty = i;
            while (ty - 1 >= 0 && map[ty - 1][j] == 0)
                ty--;
            map[i][j] = 0;
            map[ty][j] = val;
            if (ty - 1 >= 0 && map[ty][j] == map[ty - 1][j] && !doubled[ty - 1][j])
            {
                map[ty][j] = 0;
                map[ty - 1][j] *= 2;
                doubled[ty - 1][j] = true;
            }
        }
    }
}
void down()
{
    bool doubled[20][20] = {false};
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 0)
                continue;
            int val = map[i][j], ty = i;
            while (ty + 1 < n && map[ty + 1][j] == 0)
                ty++;
            map[i][j] = 0;
            map[ty][j] = val;
            if (ty + 1 < n && map[ty][j] == map[ty + 1][j] && !doubled[ty + 1][j])
            {
                map[ty][j] = 0;
                map[ty + 1][j] *= 2;
                doubled[ty + 1][j] = true;
            }
        }
    }
}
void left()
{
    bool doubled[20][20] = {false};
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (map[i][j] == 0)
                continue;
            int val = map[i][j], tx = j;
            while (tx - 1 >= 0 && map[i][tx - 1] == 0)
                tx--;
            map[i][j] = 0;
            map[i][tx] = val;
            if (tx - 1 >= 0 && map[i][tx] == map[i][tx - 1] && !doubled[i][tx - 1])
            {
                map[i][tx] = 0;
                map[i][tx - 1] *= 2;
                doubled[i][tx - 1] = true;
            }
        }
    }
}
void right()
{
    bool doubled[20][20] = {false};
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (map[i][j] == 0)
                continue;
            int val = map[i][j], tx = j;
            while (tx + 1 < n && map[i][tx + 1] == 0)
                tx++;
            map[i][j] = 0;
            map[i][tx] = val;
            if (tx + 1 < n && map[i][tx] == map[i][tx + 1] && !doubled[i][tx + 1])
            {
                map[i][tx] = 0;
                map[i][tx + 1] *= 2;
                doubled[i][tx + 1] = true;
            }
        }
    }
}
void (*Move[4])() = {up, down, left, right};
bool same(int &dep, int (*backup)[20])
{
    bool sameflag = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sameflag &= (backup[i][j] == map[i][j]);
        }
    }
    return sameflag;
}
int expected(int &dep)
{
    int tmax = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (tmax < map[i][j])
                tmax = map[i][j];
    return tmax * (1 << (MAXDEP - dep));
}
void bf(int dep)
{
    if (dep == MAXDEP)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (ans < map[i][j])
                    ans = map[i][j];
        return;
    }

    if (expected(dep) <= ans)
        return;

    int backup[20][20];
    for (int i = 0; i < 4; i++)
    {
        memcpy(backup, map, sizeof(int) * 400);
        Move[i]();
        if (same(dep, backup))
            continue;
        bf(dep + 1);
        memcpy(map, backup, sizeof(int) * 400);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (ans < map[i][j])
                ans = map[i][j];
        }

    bf(0);
    cout << ans;
}