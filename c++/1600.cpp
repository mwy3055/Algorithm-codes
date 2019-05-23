#include <bits/stdc++.h>
using namespace std;

int h, w, k;
bool Map[200][200];

class Coord
{
public:
    int y, x, k;
    Coord(int y = 0, int x = 0, int k = 0) : y(y), x(x), k(k) {}
    static bool isin(int y, int x)
    {
        return 0 <= y && y < h && 0 <= x && x < w;
    }
};
/*
    visit�� 3������ ����
    ���� �ڵ忡�� visit�� 2�����̶��, ����Ʈ�� �̵��� �� visit�� �����ϰ� �ȴ�.
    �׷��� �̰��� �ּ��� �ƴ� ���� �ִ�. ���� ����Ʈ�� ������ Ƚ�� k�� �������� visit�� �˻��ؾ� �Ѵ�.
*/
int bfs()
{
    queue<Coord> q;
    bool visit[200][200][31] = {false};
    int src[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int ksrc[8][2] = {2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -2, 1, -1, 2, 1, 2};

    int rtn = 0;
    visit[0][0][k] = true;
    q.push(Coord(0, 0, k));
    while (!q.empty())
    {
        int siz = q.size();
        while (siz--)
        {
            Coord top = q.front();
            q.pop();

            if (top.y == h - 1 && top.x == w - 1)
                return rtn;

            if (0 < top.k)
            {
                for (int i = 0; i < 8; i++)
                {
                    int sy = top.y + ksrc[i][0], sx = top.x + ksrc[i][1];
                    if (Coord::isin(sy, sx) && !Map[sy][sx] && !visit[sy][sx][top.k - 1])
                    {
                        visit[sy][sx][top.k - 1] = true;
                        q.push(Coord(sy, sx, top.k - 1));
                    }
                }
            }

            for (int i = 0; i < 4; i++)
            {
                int sy = top.y + src[i][0], sx = top.x + src[i][1];
                if (Coord::isin(sy, sx) && !Map[sy][sx] && !visit[sy][sx][top.k])
                {
                    visit[sy][sx][top.k] = true;
                    q.push(Coord(sy, sx, top.k));
                }
            }
        }
        rtn++;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> w >> h;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> Map[i][j];

    cout << bfs();
}