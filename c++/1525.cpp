#include <bits/stdc++.h>
using namespace std;

class Map
{
public:
    enum dir
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    int arr[3][3];
    int y, x;
    Map() {}
    Map(int (*arr)[3], int y, int x) : y(y), x(x)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                this->arr[i][j] = arr[i][j];
    }
    bool isclear()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] != ((i == 2 && j == 2) ? 0 : (i * 3 + (j + 1))))
                    return false;
            }
        }
        return true;
    }
    int toint()
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
    Map move(dir d)
    {
        Map temp = *this;
        switch (d)
        {
        case Map::LEFT:
            if (temp.x != 0)
            {
                temp.arr[y][x] = temp.arr[y][x - 1];
                temp.arr[y][x - 1] = 0;
                temp.x--;
            }
            break;
        case Map::RIGHT:
            if (temp.x != 2)
            {
                temp.arr[y][x] = temp.arr[y][x + 1];
                temp.arr[y][x + 1] = 0;
                temp.x++;
            }
            break;
        case Map::DOWN:
            if (temp.y != 2)
            {
                temp.arr[y][x] = temp.arr[y + 1][x];
                temp.arr[y + 1][x] = 0;
                temp.y++;
            }
            break;
        default: //UP
            if (temp.y != 0)
            {
                temp.arr[y][x] = temp.arr[y - 1][x];
                temp.arr[y - 1][x] = 0;
                temp.y--;
            }
            break;
        }
        return temp;
    }
};
set<int> s;

int bfs(Map &first)
{
    if (first.isclear())
        return 0;

    queue<Map> q;

    s.insert(first.toint());
    q.push(first);

    int nth = 1;
    while (!q.empty())
    {
        int siz = q.size();
        while (siz--)
        {
            Map top = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                Map next = top.move((Map::dir)i);
                if (next.isclear())
                    return nth;

                if (s.find(next.toint()) == s.end())
                {
                    s.insert(next.toint());
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

    int arr[3][3], y, x;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
            {
                y = i;
                x = j;
            }
        }
    }

    Map first(arr, y, x);
    cout << bfs(first);
}