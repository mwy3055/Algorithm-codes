#include <bits/stdc++.h>
using namespace std;

int factorial[11];

int solve(int &n, int dep, bool *selected, bool (*isFriend)[10])
{
    if (n == dep * 2)
        return 1;

    int ret = 0;
    for (int a = 0; a < n; a++)
    {
        if (selected[a]) //중복 제거: (2, 3), (0, 1)을 세지 않도록
            continue;
        for (int b = a + 1; b < n; b++)
        {
            if (!selected[b] && isFriend[a][b])
            {
                selected[a] = selected[b] = true;
                ret += solve(n, dep + 1, selected, isFriend);
                selected[a] = selected[b] = false;
            }
        }
        break; //중복 제거: (0, 1)을 센 후 (1, 0)을 세지 않도록
    }
    return ret;
}

void init()
{
    factorial[0] = 1;
    for (int i = 1; i <= 10; i++)
    {
        factorial[i] = factorial[i - 1] * i;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    int c;
    cin >> c;
    while (c--)
    {
        int n, m;
        cin >> n >> m;
        bool isFriend[10][10] = {false};
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            isFriend[a][b] = isFriend[b][a] = true;
        }

        bool selected[10] = {false};
        cout << solve(n, 0, selected, isFriend) << '\n';
    }
}