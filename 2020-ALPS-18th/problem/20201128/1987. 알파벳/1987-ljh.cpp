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
            check[board[ny][nx]] = false; //��Ʈ��ŷ!! 
            //�� ��θ� ��� Ž���� �������� �� ��ο��� üũ�� ���ĺ��� ��� �湮üũ ����!
            // �ٸ� ��η� ���� ��쵵 ��� ���ϱ� ����! 
            // ABC
            // BAA ���� ��� ������ ���� �������� AB �Ѱͺ��� ���������ΰ��� ABC�� �� ���
            // ���� B�� �湮�� ���� üũ ���� ����� ���� �� ��θ� ���� �� ����! 
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
