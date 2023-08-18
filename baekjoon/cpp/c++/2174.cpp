#include <bits/stdc++.h>

// 0: 동, 1: 남, 2: 서, 3: 북
int a, b, dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int map[101][101];

bool isin(int x, int y)
{
    return 1 <= x && x <= a && 1 <= y && y <= b;
}

class robot
{
public:
    int x, y, dir, rno;
    robot(int x, int y, int dir, int robot_no) : x(x), y(y), dir(dir), rno(robot_no)
    {
        map[x][y] = robot_no;
    }
    void turn_left(int count = 1)
    {
        for (int i = 0; i < count; i++)
            dir = ((dir - 1) + 4) % 4;
    }
    void turn_right(int count = 1)
    {
        for (int i = 0; i < count; i++)
            dir = (dir + 1) % 4;
    }
    int go(int count = 1)
    {
        for (int i = 0; i < count; i++)
        {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (!isin(nx, ny)) // crashes into wall
                return 1;
            else if (map[nx][ny] != 0) // crashes into robot
                return 2;
            map[x][y] = 0;
            x = nx, y = ny;
            map[x][y] = rno;
        }
        return 0;
    }
    std::pair<int, int> get_next()
    {
        return std::make_pair(x + dx[dir], y + dy[dir]);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> a >> b >> n >> m;
    std::map<char, int> dir_map = {{'E', 0}, {'S', 1}, {'W', 2}, {'N', 3}};
    std::vector<robot> robots;
    robots.emplace_back(0, 0, 0, -1);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        char d;
        std::cin >> x >> y >> d;
        robots.emplace_back(x, y, dir_map[d], i);
    }

    bool crash = false;
    for (int i = 0; i < m; i++)
    {
        int rno, iter;
        char command;
        std::cin >> rno >> command >> iter;
        if (command == 'L')
        {
            robots[rno].turn_left(iter);
        }
        else if (command == 'R')
        {
            robots[rno].turn_right(iter);
        }
        else
        {
            int result = robots[rno].go(iter);
            if (result == 1)
            {
                std::cout << "Robot " << rno << " crashes into the wall" << '\n';
                crash = true;
                break;
            }
            else if (result == 2)
            {
                auto next = robots[rno].get_next();
                auto nx = next.first, ny = next.second;
                std::cout << "Robot " << rno << " crashes into robot " << map[nx][ny] << '\n';
                crash = true;
                break;
            }
        }
    }
    if (!crash)
        std::cout << "OK" << '\n';
}