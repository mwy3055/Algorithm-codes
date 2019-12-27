#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> coord;
const int INF = 0x3f3f3f3f;

int map[50][50], n, m, empty_count; // empty: 0
int ans = INF;

vector<coord> virus;
int vsize;

inline bool isin(int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < n;
}
int bfs(int *arr) // 퍼뜨리는 최소 시간
{
    static int src[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool visit[50][50] = {false};
    int tans = 0, left = empty_count;

    queue<coord> q;
    for (int i = 0; i < vsize; i++)
    {
        if (arr[i])
        {
            q.push(virus[i]);
            visit[virus[i].first][virus[i].second] = true;
        }
    }

    int endedwithtwo = 0;
    while (!q.empty() && left)
    {
        int qsize = q.size();
        for (int a = 0; a < qsize; a++)
        {
            auto &top = q.front();
            q.pop();
            int &ty = top.first, &tx = top.second;
            for (int i = 0; i < 4; i++)
            {
                int sy = ty + src[i][0], sx = tx + src[i][1];
                if (isin(sy, sx))
                {
                    if (map[sy][sx] == 0 && !visit[sy][sx])
                    {
                        q.push(coord(sy, sx));
                        visit[sy][sx] = true;
                        left--;
                    }
                    else if (map[sy][sx] == 2 && !visit[sy][sx])
                    {
                        q.push(coord(sy, sx));
                        visit[sy][sx] = true;
                    }
                }
            }
        }

        if (!q.empty())
            tans++;
    }

    return (left <= 0 ? tans : INF);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
            {
                empty_count++;
            }
            else if (map[i][j] == 2)
            {
                virus.push_back({i, j});
            }
        }
    }
    vsize = virus.size();

    int arr[vsize] = {0};
    for (int i = 0; i < m; i++)
        arr[i] = 1;

    do
    {
        ans = min(ans, bfs(arr));
    } while (prev_permutation(arr, arr + vsize));

    cout << (ans == INF ? -1 : ans);
}