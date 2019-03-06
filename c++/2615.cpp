#include <iostream>
using namespace std;

int map[19][19];

inline bool isin(int y, int x)
{
    return 0 <= y && y < 19 && 0 <= x && x < 19;
}

bool check(int i, int j)
{
    //������ ã�� �� true ����
    int src[][2] = {{0, 1},
                    {1, 1},
                    {1, 0},
                    {-1, 1}};

    for (int nth = 0; nth < 4; nth++)
    {
        int cy = i - src[nth][0], cx = j - src[nth][1];
        if (isin(cy, cx) && map[i][j] == map[cy][cx])
            continue;

        int k = 1, sy = i + src[nth][0], sx = j + src[nth][1];
        while (isin(sy, sx) && map[i][j] == map[sy][sx])
        {
            k++;
            sy += src[nth][0], sx += src[nth][1];
        }
        if (k == 5)
        {
            cout << map[i][j] << '\n'
                 << i + 1 << " " << j + 1;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++)
            cin >> map[i][j];

    //�Ʒ�, �Ʒ� ������, ������, ������ ���� �˻�
    //�˻� ������ �ݴ���⿡ ���� ���� ������ �˻� �ǳʶ�
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (map[i][j] != 0 && check(i, j))
                return 0;
        }
    }
    cout << 0;
}