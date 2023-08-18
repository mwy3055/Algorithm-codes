#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
//1~1413
struct coord
{
    int y, x;
    bool operator==(coord &i)
    {
        return this->y == i.y && this->x == i.x;
    }
};
int n, k;
vector<coord> isl;

int f(coord &i, coord &j) //두 섬 사이를 이동하는 데 드는 연료
{
    return (int)ceil(sqrt((i.x - j.x) * (i.x - j.x) + (i.y - j.y) * (i.y - j.y)) / 10);
}
bool bfs(int m)
{
    //최대 가능 거리:m*10
    bool visit[1002] = {false};

    int idx = 0;
    queue<coord> q;
    q.push({0, 0});
    while (!q.empty() && idx <= k)
    {
        int siz = q.size();
        for (int a = 0; a < siz; a++)
        {
            coord &top = q.front();
            q.pop();
            for (int i = 0; i <= n; i++)
            {
                if (!visit[i] && f(top, isl[i]) <= m)
                {
                    if (i == n)
                        return true;
                    q.push(isl[i]);
                    visit[i] = true;
                }
            }
        }
        idx++;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    isl = vector<coord>(n + 1);
    for (int i = 0; i < n; i++)
        cin >> isl[i].x >> isl[i].y;
    isl[n] = {10000, 10000};

    int s = 1, e = 1413;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (bfs(m))
            e = m - 1;
        else
            s = m + 1;
    }
    cout << s;
}