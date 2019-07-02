#include <bits/stdc++.h>
using namespace std;

enum dir
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};
bool isclear(int n)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((n % 10) != ((i == 2 && j == 2) ? 0 : (i * 3 + (j + 1))))
                return false;
            n /= 10;
        }
    }
    return true;
}
int toint(int (*arr)[3])
{
    int sq = 1, rtn = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            rtn += sq * arr[i][j];
            sq *= 10;
        }
    }
    return rtn;
}
void toarr(int n, int (*arr)[3], int &y, int &x)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = n % 10;
            if (arr[i][j] == 0)
            {
                y = i;
                x = j;
            }
            n /= 10;
        }
    }
}
int move(int n, dir d)
{
    int arr[3][3], y, x;
    toarr(n, arr, y, x);

    switch (d)
    {
    case LEFT:
        if (x != 0)
        {
            arr[y][x] = arr[y][x - 1];
            arr[y][x - 1] = 0;
        }
        break;
    case RIGHT:
        if (x != 2)
        {
            arr[y][x] = arr[y][x + 1];
            arr[y][x + 1] = 0;
        }
        break;
    case DOWN:
        if (y != 2)
        {
            arr[y][x] = arr[y + 1][x];
            arr[y + 1][x] = 0;
        }
        break;
    default: //UP
        if (y != 0)
        {
            arr[y][x] = arr[y - 1][x];
            arr[y - 1][x] = 0;
        }
        break;
    }
    return toint(arr);
}

int bfs(int first)
{
    if (isclear(first))
        return 0;

    set<int> s;
    queue<int> q;

    s.insert(first);
    q.push(first);

    int nth = 1;
    while (!q.empty())
    {
        int siz = q.size();
        while (siz--)
        {
            int top = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int next = move(top, (dir)i);
                if (isclear(next))
                    return nth;

                if (s.find(next) == s.end())
                {
                    s.insert(next);
                    q.push(next);
                }
            }
        }
        nth++;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << bfs(toint(arr));
}