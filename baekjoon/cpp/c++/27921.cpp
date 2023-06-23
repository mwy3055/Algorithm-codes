#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 987654321;

char c1[11][11];
char c2[31][31];

const int DH = 10, DW = 10;

int H1, W1, H2, W2;
int max_H = 0;
int max_W = 0;
int cnt = 0;
int maxV = 0;

void func(int idx_H, int idx_W) // 우로 이동 탐색
{
    cnt = 0;
    for (int i = 0; i < H1; i++)
    {
        for (int j = 0; j < W1; j++)
        {
            if (c1[i][j] == c2[idx_H + i][idx_W + j] && c2[idx_H + i][idx_W + j] == 'O')
                cnt++;
        }
    }
    maxV = max(maxV, cnt);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> H1 >> W1;

    for (int i = 0; i < H1; i++)
    {
        for (int j = 0; j < W1; j++)
        {
            cin >> c1[i][j];
        }
    }

    cin >> H2 >> W2;

    int total = 0;
    for (int i = 0; i < H2; i++)
    {
        for (int j = 0; j < W2; j++)
        {
            cin >> c2[DH + i][DW + j];
            if (c2[DH + i][DW + j] == 'O')
                total++; // 총 개수 카운트
        }
    }

    for (int i = 0; i <= 30 - H1; i++)
    {
        for (int j = 0; j <= 30 - W1; j++)
        {
            func(i, j);
        }
    }

    // int idx_H = 0;
    // while (idx_H < H1) // 아래로 하나씩 이동
    // {
    //     func(idx_H, 0);
    //     idx_H++;
    // }

    cout << total - maxV;

    return 0;
}