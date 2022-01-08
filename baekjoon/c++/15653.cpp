#include <bits/stdc++.h>

int n, m;
char map[11][11];
bool visit[110][110];

struct coord
{
    int r, c;
    coord(int r = 0, int c = 0) : r(r), c(c) {}
    int index()
    {
        return r * 10 + c;
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
    coord operator-(coord other)
    {
        return coord(r - other.r, c - other.c);
    }
    bool operator!=(coord other)
    {
        return r != other.r || c != other.c;
    }
};

struct node
{
    coord red, blue;
    node(coord red, coord blue) : red(red), blue(blue) {}
};

coord d[] = {coord(0, 1), coord(1, 0), coord(0, -1), coord(-1, 0)};

void getInput()
{
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> map[i];
    }
}

coord findLetter(char letter)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == letter)
            {
                return coord(i, j);
            }
        }
    }
    return coord(-1, -1);
}

bool redFirst(coord &red, coord &blue, int &dir)
{
    switch (dir)
    {
    case 0:
        return red.r != blue.r || red.c > blue.c;
    case 1:
        return red.c != blue.c || red.r > blue.r;
    case 2:
        return red.r != blue.r || red.c < blue.c;
    case 3:
        return red.c != blue.c || red.r < blue.r;
    default:
        return false;
    }
}

bool move(coord &c, int &dir, coord other = coord(-1, -1))
{
    bool hole = false;
    coord next = c + d[dir];
    while (map[next.r][next.c] != '#' && next != other)
    {
        if (map[next.r][next.c] == 'O')
        {
            hole = true;
        }
        next += d[dir];
    }
    c = next - d[dir];
    return hole;
}

int solve()
{
    auto out = coord(-1, -1);
    // find balls
    auto red = findLetter('R');
    auto blue = findLetter('B');
    // BFS 시작

    std::queue<node> q;
    q.push(node(red, blue));
    visit[red.index()][blue.index()] = true;

    int count = 0;
    while (!q.empty())
    {
        count++;
        int size = q.size();
        while (size--)
        {
            auto [red, blue] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                auto &diff = d[i];
                auto nextRed = red, nextBlue = blue;
                // 빨간(파란) 공이 구멍을 지나갔는가?
                auto redHole = false, blueHole = false;
                // 어느 공이 먼저 움직여야 하는가?
                // 먼저 움직인 공이 구멍에 들어갔다면, 나중에 움직인 공도 구멍에 들어갈 수 있다.
                if (redFirst(red, blue, i))
                {
                    redHole = move(nextRed, i);
                    blueHole = move(nextBlue, i, redHole ? out : nextRed);
                }
                else
                {
                    blueHole = move(nextBlue, i);
                    redHole = move(nextRed, i, blueHole ? out : nextBlue);
                }
                // 결과 확인
                if (redHole && !blueHole)
                {
                    return count;
                }
                else if (!blueHole)
                {
                    if (!visit[nextRed.index()][nextBlue.index()])
                    {
                        q.emplace(nextRed, nextBlue);
                        visit[nextRed.index()][nextBlue.index()] = true;
                    }
                }
                else
                {
                    continue;
                }
            }
        }
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