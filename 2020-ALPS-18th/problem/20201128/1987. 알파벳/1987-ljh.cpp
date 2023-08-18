#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;

int board[MAX+1][MAX+1];
int check[27];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int R, C, cnt, ans;

bool isin(int x, int y)
{
    return (0 <= x && x < C && 0 <= y && y < R);
}

int ctoi(char c) { return c >= 'A' && c <= 'Z' ? c - 'A' : c - 'a' + 26; }

void dfs(int x, int y, int cnt)
{
    ans = max(ans, cnt);

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isin(nx, ny) && !check[board[ny][nx]])
        {
            check[board[ny][nx]] = true;
            // cout << board[nx][ny] << '\n';
            dfs(nx, ny, cnt+1);
            check[board[ny][nx]] = false; //백트래킹!! 
            //한 경로를 모두 탐색한 다음에는 그 경로에서 체크한 알파벳은 모두 방문체크 해제!
            // 다른 경로로 가는 경우도 모두 구하기 위해! 
            // ABC
            // BAA 같은 경우 밑으로 먼저 내려가서 AB 한것보다 오른쪽으로가서 ABC가 더 길다
            // 따라서 B를 방문한 것을 체크 해제 해줘야 가장 긴 경로를 구할 수 있음! 
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        string inp;
        cin >> inp;
        for (int j = 0; j < C; j++)
        {
            board[i][j] = ctoi(inp[j]);
            // cout << board[i][j] << '\n';
        }
    }
    check[board[0][0]] = true;

    // cnt = 1;

    dfs(0, 0, 1);

    cout << ans << '\n';

    return 0;
}
