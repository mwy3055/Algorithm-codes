#include <bits/stdc++.h>

using namespace std;

int tc, n, ans;

int camp[3000][3]; // x, y, r
bool check[3000];
//  캠프 연결 여부를 표현하는 배열
int connect[3000][3000];

void initialize()
{
    ans = 0;
    memset(camp, 0, sizeof(camp));
    memset(check, false, sizeof(check));
    memset(connect, 0, sizeof(connect));
}

void input()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> camp[i][0] >> camp[i][1] >> camp[i][2];
    }
}

void solution()
{
    //연결관계 확인 
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = camp[i][0] - camp[j][0];
            int y = camp[i][1] - camp[j][1];

            int r = camp[i][2] + camp[j][2];
            int d = x * x + y * y;

            // 만약 닿거나 공통된 부분이 있으면
            if (d <= (r * r))
            {
                connect[i][j] = 1;
                connect[j][i] = 1;
            }
        }
    }

    //영역 개수 세기
    int cnt = 0;

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (check[i] == 0)
        {
            cnt++;

            check[i] = 1;
            q.push(i);
            
            while (!q.empty())
            {
                int idx = q.front();
                q.pop();
               
                for (int j = 0; j < n; j++)
                {
                    if (connect[idx][j] == 1 && check[j] == 0)
                    {
                        check[j] = 1;
                        q.push(j);
                    }
                }
            }
        }
    }

    ans = cnt;
}

void solve()
{
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        initialize();
        input();
        solution();

        cout << ans << '\n';
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

