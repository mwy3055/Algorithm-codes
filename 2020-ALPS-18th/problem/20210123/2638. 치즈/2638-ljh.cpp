#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int n, m, ans;
int board[MAX + 1][MAX + 1]; // 1:치즈 0: 공기
int check[MAX + 1][MAX + 1]; // 공기와 닿은 횟수, 0이면 방문하지 않은 것 


int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void initialize_check()
{
    memset(check, 0, sizeof(check));
}

void melting()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //외부 공기와 두 면이나 접촉한 치즈만 제거 
            if (board[i][j] == 1 && check[i][j] >= 2)
                board[i][j] = 0;
        }
    }
}

int remain_cheeze_cnt()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1)
                cnt++;
        }
    }
    return cnt;
}

void bfs()
{
    queue<pair<int, int>> q;
    q.push({0, 0});

    //치즈의 외부에서 탐색 시작 
    check[0][0] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                //치즈가 아닌 공기 부분만 탐색, 치즈 내부로는 들어가지 탐색하지 않음 
                if (board[nx][ny] == 0 && check[nx][ny] == 0)
                {
                    check[nx][ny] = 1;
                    q.push({nx, ny});
                }
                else if (board[nx][ny] == 1)
                {
                    check[nx][ny] += 1;
                }
            }
        }
    }
}

void input()
{
    cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
}


void solve()
{
    input();

    int cnt = 0;

    while (true)
    {
        initialize_check();

        if (remain_cheeze_cnt() == 0)
            break;
        else
            cnt++;

        bfs();

        melting();
    }
    ans = cnt;

    cout << ans << '\n';
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}