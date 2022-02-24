#include <bits/stdc++.h>
using namespace std;

//각 칸에 나무 정보를 저장하자.
deque<int> tr[10][10];
int n, m, k;
int Map[10][10], A[10][10]; //양분 저장

void getinput(int &n, int &m, int &k)
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
            Map[i][j] = 5;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int y, x, age;
        cin >> y >> x >> age;
        tr[y - 1][x - 1].push_back(age);
    }
}

bool isin(int &y, int &x)
{
    return 0 <= y && y < n && 0 <= x && x < n;
}
void spring_summer()
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            sort(tr[y][x].begin(), tr[y][x].end());
            int siz = tr[y][x].size();
            for (int i = 0; i < siz; i++)
            {
                int &age = tr[y][x][i];
                if (age <= Map[y][x])
                    Map[y][x] -= age++;
                else
                {
                    for (int j = i; j < siz; j++) //삭제
                    {
                        Map[y][x] += tr[y][x][j] / 2;
                    }
                    tr[y][x].erase(tr[y][x].begin() + i, tr[y][x].end());
                    break;
                }
            }
        }
    }
}
void fall()
{
    int src[][2] = {-1, 0,
                    -1, 1,
                    0, 1,
                    1, 1,
                    1, 0,
                    1, -1,
                    0, -1,
                    -1, -1};
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            int siz = tr[y][x].size();
            for (int a = 0; a < siz; a++)
            {
                int &age = tr[y][x][a];
                if (age % 5 == 0)
                {
                    for (int i = 0; i < 8; i++)
                    {
                        int sy = y + src[i][0], sx = x + src[i][1];
                        if (isin(sy, sx))
                        {
                            tr[sy][sx].push_back(1);
                        }
                    }
                }
            }
        }
    }
}
void winter()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Map[i][j] += A[i][j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    getinput(n, m, k);

    while (k--)
    {
        spring_summer();
        fall();
        winter();
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans += tr[i][j].size();
    cout << ans;
}