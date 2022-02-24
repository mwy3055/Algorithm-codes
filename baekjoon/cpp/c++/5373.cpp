#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
vvc UP, DOWN, FRONT, BACK, LEFT, RIGHT;
void init()
{
    UP = vvc(3, vc(3, 'w'));
    DOWN = vvc(3, vc(3, 'y'));
    FRONT = vvc(3, vc(3, 'r'));
    BACK = vvc(3, vc(3, 'o'));
    LEFT = vvc(3, vc(3, 'g'));
    RIGHT = vvc(3, vc(3, 'b'));
}
void cw(vvc &a)
{
    vvc b = a;
    for (int i = 0; i < 3; i++)
        a[i][2] = b[0][i];
    a[0][0] = b[2][0], a[0][1] = b[1][0], a[0][2] = b[0][0];
    for (int i = 0; i < 3; i++)
        a[i][0] = b[2][i];
    a[2][0] = b[2][2], a[2][1] = b[1][2], a[2][2] = b[0][2];
}
void ccw(vvc &a)
{
    vvc b = a;
    for (int i = 0; i < 3; i++)
        a[0][i] = b[i][2];
    a[0][2] = b[2][2], a[1][2] = b[2][1], a[2][2] = b[2][0];
    for (int i = 0; i < 3; i++)
        a[2][i] = b[i][0];
    a[2][0] = b[0][0], a[1][0] = b[0][1], a[0][0] = b[0][2];
}
void rotate(char face, char dir)
{
    if (face == 'U')
    {
        if (dir == '+')
        {
            cw(UP);
            vc backup = RIGHT[0];
            RIGHT[0] = BACK[0];
            BACK[0] = LEFT[0];
            LEFT[0] = FRONT[0];
            FRONT[0] = backup;
        }
        else
        {
            ccw(UP);
            vc backup = FRONT[0];
            FRONT[0] = LEFT[0];
            LEFT[0] = BACK[0];
            BACK[0] = RIGHT[0];
            RIGHT[0] = backup;
        }
    }
    if (face == 'D')
    {
        if (dir == '+')
        {
            cw(DOWN);
            vc backup = FRONT[2];
            FRONT[2] = LEFT[2];
            LEFT[2] = BACK[2];
            BACK[2] = RIGHT[2];
            RIGHT[2] = backup;
        }
        else
        {
            ccw(DOWN);
            vc backup = FRONT[2];
            FRONT[2] = RIGHT[2];
            RIGHT[2] = BACK[2];
            BACK[2] = LEFT[2];
            LEFT[2] = backup;
        }
    }
    if (face == 'F')
    {
        if (dir == '+')
        {
            cw(FRONT);
            vc backup = UP[2];
            UP[2][0] = LEFT[2][2], UP[2][1] = LEFT[1][2], UP[2][2] = LEFT[0][2];
            for (int i = 0; i < 3; i++)
                LEFT[i][2] = DOWN[0][i];
            DOWN[0][0] = RIGHT[2][0], DOWN[0][1] = RIGHT[1][0], DOWN[0][2] = RIGHT[0][0];
            for (int i = 0; i < 3; i++)
                RIGHT[i][0] = backup[i];
        }
        else
        {
            ccw(FRONT);
            vc backup = UP[2];
            for (int i = 0; i < 3; i++)
                UP[2][i] = RIGHT[i][0];
            RIGHT[0][0] = DOWN[0][2], RIGHT[1][0] = DOWN[0][1], RIGHT[2][0] = DOWN[0][0];
            for (int i = 0; i < 3; i++)
                DOWN[0][i] = LEFT[i][2];
            LEFT[2][2] = backup[0], LEFT[1][2] = backup[1], LEFT[0][2] = backup[2];
        }
    }
    if (face == 'B')
    {
        if (dir == '+')
        {
            cw(BACK);
            vc backup = UP[0];
            for (int i = 0; i < 3; i++)
                UP[0][i] = RIGHT[i][2];
            RIGHT[0][2] = DOWN[2][2], RIGHT[1][2] = DOWN[2][1], RIGHT[2][2] = DOWN[2][0];
            for (int i = 0; i < 3; i++)
                DOWN[2][i] = LEFT[i][0];
            LEFT[2][0] = backup[0], LEFT[1][0] = backup[1], LEFT[0][0] = backup[2];
        }
        else
        {
            ccw(BACK);
            vc backup = UP[0];
            UP[0][0] = LEFT[2][0], UP[0][1] = LEFT[1][0], UP[0][2] = LEFT[0][0];
            for (int i = 0; i < 3; i++)
                LEFT[i][0] = DOWN[2][i];
            DOWN[2][0] = RIGHT[2][2], DOWN[2][1] = RIGHT[1][2], DOWN[2][2] = RIGHT[0][2];
            for (int i = 0; i < 3; i++)
                RIGHT[i][2] = backup[i];
        }
    }
    if (face == 'R')
    {
        if (dir == '+')
        {
            cw(RIGHT);
            vvc backup = BACK;
            BACK[0][0] = UP[2][2], BACK[1][0] = UP[1][2], BACK[2][0] = UP[0][2];
            for (int i = 0; i < 3; i++)
                UP[i][2] = FRONT[i][2];
            for (int i = 0; i < 3; i++)
                FRONT[i][2] = DOWN[i][2];
            DOWN[0][2] = backup[2][0], DOWN[1][2] = backup[1][0], DOWN[2][2] = backup[0][0];
        }
        else
        {
            ccw(RIGHT);
            vvc backup = FRONT;
            for (int i = 0; i < 3; i++)
                FRONT[i][2] = UP[i][2];
            UP[0][2] = BACK[2][0], UP[1][2] = BACK[1][0], UP[2][2] = BACK[0][0];
            BACK[0][0] = DOWN[2][2], BACK[1][0] = DOWN[1][2], BACK[2][0] = DOWN[0][2];
            for (int i = 0; i < 3; i++)
                DOWN[i][2] = backup[i][2];
        }
    }
    if (face == 'L')
    {
        if (dir == '+')
        {
            cw(LEFT);
            vvc backup = UP;
            UP[0][0] = BACK[2][2], UP[1][0] = BACK[1][2], UP[2][0] = BACK[0][2];
            BACK[0][2] = DOWN[2][0], BACK[1][2] = DOWN[1][0], BACK[2][2] = DOWN[0][0];
            for (int i = 0; i < 3; i++)
                DOWN[i][0] = FRONT[i][0];
            for (int i = 0; i < 3; i++)
                FRONT[i][0] = backup[i][0];
        }
        else
        {
            ccw(LEFT);
            vvc backup = UP;
            for (int i = 0; i < 3; i++)
                UP[i][0] = FRONT[i][0];
            for (int i = 0; i < 3; i++)
                FRONT[i][0] = DOWN[i][0];
            DOWN[0][0] = BACK[2][2], DOWN[1][0] = BACK[1][2], DOWN[2][0] = BACK[0][2];
            BACK[0][2] = backup[2][0], BACK[1][2] = backup[1][0], BACK[2][2] = backup[0][0];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        init();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string m;
            cin >> m;
            rotate(m[0], m[1]);
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                cout << UP[i][j];
            cout << '\n';
        }
    }
}