#include <bits/stdc++.h>

int row, col;
bool map[100][100], visit[100][100][4];

struct coord
{
    int r, c;
    coord(int r = -1, int c = -1) : r(r), c(c) {}
    bool isin()
    {
        return 0 <= this->r && this->r < row &&
               0 <= this->c && this->c < col;
    }
    coord operator+(coord other)
    {
        return coord(r + other.r, c + other.c);
    }
    void operator+=(coord other)
    {
        r += other.r;
        c += other.c;
    }
    bool operator==(coord other)
    {
        return r == other.r &&
               c == other.c;
    }
};

struct robot
{
    coord c;
    int dir;
    robot(coord c = coord(), int dir = 0) : c(c), dir(dir) {}
    bool isin()
    {
        return c.isin();
    }
    bool operator==(robot &other)
    {
        return c == other.c && dir == other.dir;
    }
    bool operator!=(robot &other)
    {
        return !((*this) == other);
    }
    void operator+=(coord move)
    {
        c += move;
    }
};

robot start, target;

coord d[] = {coord(0, 1), coord(0, -1), coord(1, 0), coord(-1, 0)};
int left[] = {3, 2, 0, 1};
int right[] = {2, 3, 1, 0};

void getInput()
{
    std::cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cin >> map[i][j];
        }
    }
    int r, c, dir;
    std::cin >> r >> c >> dir;
    start = robot(coord(r - 1, c - 1), dir - 1);
    std::cin >> r >> c >> dir;
    target = robot(coord(r - 1, c - 1), dir - 1);
}

bool canGo(robot &r)
{
    return r.isin() && map[r.c.r][r.c.c] == 0;
}

// 로봇 r을 방향 dir로 k만큼 움직일 수 있는가?
bool move(robot &r, int dir, int k)
{
    auto next = r;
    for (int i = 0; i < k; i++)
    {
        next += d[dir];
        if (!canGo(next))
            return false;
    }
    r = next;
    return true;
}

bool &getVisitRef(robot &r)
{
    return visit[r.c.r][r.c.c][r.dir];
}

robot rotate(robot &r, bool isLeft)
{
    int rotateDir = isLeft ? left[r.dir] : right[r.dir];
    return robot(r.c, rotateDir);
}

void tryRotate(std::queue<robot> &q, robot &cur, bool isLeft)
{
    auto rotated = rotate(cur, isLeft);
    auto &visitRef = getVisitRef(rotated);
    if (!visitRef)
    {
        q.push(rotated);
        visitRef = true;
    }
}

int solve()
{
    std::queue<robot> q;

    q.push(start);
    getVisitRef(start) = true;

    int count = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            auto cur = q.front();
            q.pop();
            if (cur == target)
            {
                return count;
            }

            // 이동
            for (int k = 1; k <= 3; k++)
            {
                auto next = cur;
                if (!move(next, cur.dir, k))
                {
                    break;
                }
                auto &ref = getVisitRef(next);
                if (!ref)
                {
                    q.push(next);
                    ref = true;
                }
            }

            // 왼쪽, 오른쪽 회전, 원래 방향
            tryRotate(q, cur, true);
            tryRotate(q, cur, false);
        }
        count++;
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getInput();
    std::cout << solve() << '\n';
}