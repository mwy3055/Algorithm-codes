#include <bits/stdc++.h>

struct fish
{
    bool active;
    int num, dir;
    fish(int num = 0, int dir = 0) : num(num), dir(dir)
    {
        active = true;
    }
};

fish board[4][4];
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, -1, -1, -1, 0, 1, 1, 1};

bool isin(int r, int c)
{
    return 0 <= r && r < 4 &&
           0 <= c && c < 4;
}

bool can_go(int r, int c, int dir)
{
    int new_r = r + dr[dir];
    int new_c = c + dc[dir];
    return isin(new_r, new_c) &&
           board[new_r][new_c].num != -1;
}

void getinput()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int a, b;
            std::cin >> a >> b;
            board[i][j] = fish(a, --b);
        }
    }
}

void find_fish(int &r, int &c, int num)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            auto &cur = board[i][j];
            if (cur.active && cur.num == num)
            {
                r = i;
                c = j;
                return;
            }
        }
    }
    r = c = -1;
}

int search(fish board[4][4])
{
    int ans = 0;
    fish backup[4][4];
    memcpy(backup, board, sizeof(backup));

    int shark_r, shark_c;
    // 1. 물고기 이동
    for (int num = 1; num <= 16; num++)
    {
        int r, c;
        find_fish(r, c, num);
        // 물고기가 존재하지 않는 경우
        if (r == -1 && c == -1)
            continue;
        // 이동할 방향 탐색
        bool pass_flag = false;
        int dir = board[r][c].dir;
        int dir_backup = dir;
        while (!can_go(r, c, dir))
        {
            dir = (dir + 1) % 8;
            if (dir == dir_backup)
            {
                pass_flag = true;
                break;
            }
        }
        // 물고기가 이동할 수 있는 방향이 없는 경우
        if (pass_flag)
            continue;
        board[r][c].dir = dir;
        // 이동
        int nr = r + dr[dir], nc = c + dc[dir];
        std::swap(board[r][c], board[nr][nc]);
    }
    // 2. 상어 이동
    find_fish(shark_r, shark_c, -1);
    auto shark = board[shark_r][shark_c];
    for (int i = 1; i <= 3; i++)
    {
        int nr = shark_r + dr[shark.dir] * i;
        int nc = shark_c + dc[shark.dir] * i;
        // 물고기가 있다면 먹어 본다.
        if (isin(nr, nc) && board[nr][nc].active)
        {
            auto victim = board[nr][nc];
            std::swap(board[shark_r][shark_c], board[nr][nc]);
            // (nr, nc)에는 상어가
            // (shark_r, shark_c)에는 죽은 물고기가 있다.
            board[nr][nc].dir = victim.dir;
            board[shark_r][shark_c].active = false;
            int tans = victim.num + search(board);
            ans = std::max(ans, tans);
            // 복원
            board[shark_r][shark_c] = shark;
            board[nr][nc] = victim;
        }
    }
    // 복원
    memcpy(board, backup, sizeof(backup));
    return ans;
}

int solve()
{
    int ans = board[0][0].num;
    fish shark(-1, board[0][0].dir);
    board[0][0] = shark;

    return ans + search(board);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}