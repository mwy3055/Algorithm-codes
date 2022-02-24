#include <bits/stdc++.h>
using namespace std;

int bright[1001][1001];

void getinput(int &r, int &c)
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            int b;
            cin >> b;
            bright[i][j] = bright[i - 1][j] + bright[i][j - 1] - bright[i - 1][j - 1] + b;
        }
    }
}
int average(int &r1, int &c1, int &r2, int &c2)
{
    int sum = bright[r2][c2] - bright[r2][c1 - 1] - bright[r1 - 1][c2] + bright[r1 - 1][c1 - 1];
    int area = (r2 - r1 + 1) * (c2 - c1 + 1);
    return sum / area;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c, q;
    cin >> r >> c >> q;
    getinput(r, c);

    while (q--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << average(r1, c1, r2, c2) << '\n';
    }
}