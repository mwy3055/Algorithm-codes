#include <bits/stdc++.h>

int n, m;
char board[30][31];
int empty_count;

const int MAX = 0x3f3f3f3f;
int dist[30][30];
bool visit[30][30];
int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};

bool isin(int r, int c)
{
    return 0 <= r && r < n &&
           0 <= c && c < m;
}

int ans;

void move(int dep, int r, int c, int last_dir, int visit_count)
{
    if (visit_count == empty_count)
    {
        ans = std::min(ans, dep);
        return;
    }
    // 백트래킹
    if (ans < dep)
        return;

    for (int i = 0; i < 4; i++)
    {
        // 방금 이동했던 방향으로 중복해서 이동하지 않음
        if (i == last_dir)
            continue;
        // 한 방향으로 계속 이동
        int nr = r, nc = c, ncount = visit_count;
        while (isin(nr + dr[i], nc + dc[i]) &&
               board[nr + dr[i]][nc + dc[i]] == '.' &&
               !visit[nr + dr[i]][nc + dc[i]])
        {
            nr += dr[i];
            nc += dc[i];
            visit[nr][nc] = true;
            ncount++;
        }
        // 이 방향으로 더 이동할 수 없다면 건너뜀
        if (nr == r && nc == c)
            continue;
        move(dep + 1, nr, nc, i, ncount);
        // 흔적 지우기
        while (nr != r || nc != c)
        {
            visit[nr][nc] = false;
            nr -= dr[i];
            nc -= dc[i];
        }
    }
}

int solve()
{
    // init
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visit[i][j] = false;
        }
    }
    // 빈 칸의 수
    empty_count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '.')
                empty_count++;
        }
    }

    ans = MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '.')
            {
                visit[i][j] = true;
                move(0, i, j, -1, 1);
                visit[i][j] = false;
            }
        }
    }
    return (ans == MAX ? -1 : ans);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int case_num = 1;
    while (std::cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            std::cin >> board[i];
        }
        std::cout << "Case " << case_num << ": " << solve() << '\n';
        case_num++;
    }
}