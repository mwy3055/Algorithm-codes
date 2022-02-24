#include <bits/stdc++.h>
using namespace std;

int r, c, Map[1001][1001];
struct coord
{
    int y, x;
    coord(int y = 0, int x = 0) : y(y), x(x) {}
    bool operator==(const coord c) const
    {
        return this->y == c.y && this->x == c.x;
    }
    bool operator!=(const coord c) const
    {
        return !(*this == c);
    }
};

void vertical()
{
    //세로 방향으로 왔다갔다
    char down[r], up[r];
    for (int i = 0; i < r - 1; i++)
    {
        down[i] = 'D';
        up[i] = 'U';
    }
    down[r - 1] = up[r - 1] = '\0';

    for (int i = 1; i <= c; i++)
    {
        cout << (i % 2 ? down : up);
        if (i != c)
        {
            cout << 'R';
        }
    }
}
void horizontal()
{
    //가로 방향으로
    char right[c], left[c];
    for (int i = 0; i < c - 1; i++)
    {
        right[i] = 'R';
        left[i] = 'L';
    }
    right[c - 1] = left[c - 1] = '\0';

    for (int i = 1; i <= r; i++)
    {
        cout << (i % 2 ? right : left);
        if (i != r)
        {
            cout << 'D';
        }
    }
}

coord min_location()
{
    int ty = 1, tx = 2;
    for (int i = 1; i <= r; i++)
    {
        int j;
        if (i % 2)
            j = 2;
        else
            j = 1;
        for (; j <= c; j += 2)
        {
            if (Map[i][j] < Map[ty][tx])
            {
                ty = i;
                tx = j;
            }
        }
    }
    return coord(ty, tx);
}
coord gethornext(const coord &c)
{
    return coord(c.y, (c.x % 2 ? (c.x + 1) : (c.x - 1)));
}
coord getvernext(const coord &c)
{
    return coord(c.y + 1, c.x);
}
void avoidmin(coord min)
{
    //min을 포함하는 두 줄은 ㄹ자로, 나머지 줄은 세로로
    char down[r], up[r];
    for (int i = 0; i < r - 1; i++)
    {
        down[i] = 'D';
        up[i] = 'U';
    }
    down[r - 1] = up[r - 1] = '\0';

    int minc = (min.x % 2 ? min.x : min.x - 1);

    bool flag = false;
    for (int i = 1; i <= c; i += 2)
    {
        if (i == minc)
        {
            coord cur(1, i), endpoint(r, minc + 1);
            //ㄹ자
            while (true) //그 칸 만날때까지 내려감
            {
                if (gethornext(cur) == min)
                    break;
                cout << (cur.x % 2 ? 'R' : 'L');
                cur = gethornext(cur);

                if (getvernext(cur) == min)
                    break;
                cout << 'D';
                cur = getvernext(cur);
            }

            if (cur != endpoint)
            {
                cout << 'D';
                cur = getvernext(cur);
                while (cur != endpoint)
                {
                    cout << (cur.x % 2 ? 'R' : 'L');
                    if ((cur = gethornext(cur)) == endpoint)
                        break;

                    cout << 'D';
                    cur = getvernext(cur);
                }

                if (cur != coord(r, c))
                    cout << 'R';
            }

            flag = true;
        }
        else
        {
            if (flag)
                cout << up << 'R' << down;
            else
                cout << down << 'R' << up;

            if (i != c - 1)
                cout << 'R';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> Map[i][j];

    if (r % 2 && c % 2)
        horizontal();
    else if (r % 2)
        horizontal();
    else if (c % 2)
        vertical();
    else
        avoidmin(min_location());
}