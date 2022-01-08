#include <bits/stdc++.h>
using namespace std;

typedef struct coord
{
    int y, x; //¼ýÀÚ°¡ y, ¹®ÀÚ°¡ x
    coord(int y = 0, int x = 0) : y(y), x(x) {}
    coord operator+(const coord &c)
    {
        int ty = this->y + c.y, tx = this->x + c.x;
        return coord(ty, tx);
    }
    void operator+=(const coord &c)
    {
        this->y += c.y;
        this->x += c.x;
    }
    bool operator==(const coord &c)
    {
        return this->y == c.y && this->x == c.x;
    }
    bool operator!=(const coord &c)
    {
        return this->y != c.y || this->x != c.x;
    }
} coord;

bool isin(coord c)
{
    return 1 <= c.y && c.y <= 8 && 0 <= c.x && c.x < 8;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    coord king, stone;
    char c;
    cin >> c >> king.y;
    king.x = c - 'A';
    cin >> c >> stone.y;
    stone.x = c - 'A';

    int n;
    cin >> n;
    for (int a = 0; a < n; a++)
    {
        string op;
        coord move;
        cin >> op;
        if (op[0] == 'L')
        {
            if (op[1] == 'T') //¿ÞÂÊ À§
                move = {1, -1};
            else if (op[1] == 'B') //¿ÞÂÊ ¾Æ·¡
                move = {-1, -1};
            else //¿ÞÂÊ
                move = {0, -1};
        }
        else if (op[0] == 'R')
        {
            if (op[1] == 'T')
                move = {1, 1};
            else if (op[1] == 'B')
                move = {-1, 1};
            else
                move = {0, 1};
        }
        else if (op[0] == 'B')
            move = {-1, 0};
        else //T
            move = {1, 0};

        if (king + move == stone && isin(stone + move))
        {
            king += move;
            stone += move;
        }
        else if (isin(king + move) && king + move != stone)
        {
            king += move;
        }
    }
    cout << (char)(king.x + 'A') << king.y << '\n';
    cout << (char)(stone.x + 'A') << stone.y << '\n';
}