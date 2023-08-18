#include <iostream>
using namespace std;

int n, minv = 1e9, maxv = -1e9;
char map[5][5];

void calculate(int &val, char &op, int &val2)
{
    switch (op)
    {
    case '+':
        val += val2;
        break;
    case '-':
        val -= val2;
        break;
    default:
        val *= val2;
        break;
    }
}

void dfs(int i, int j, int val, char op)
{
    if (n <= i || n <= j)
        return;

    if ('0' <= map[i][j] && map[i][j] <= '9')
    {
        if (op != 0)
        {
            int parse = map[i][j] - '0';
            calculate(val, op, parse);
        }
        if (i == n - 1 && j == n - 1)
        {
            maxv = max(maxv, val);
            minv = min(minv, val);
            return;
        }
        dfs(i + 1, j, val, 0);
        dfs(i, j + 1, val, 0);
    }
    else
    {
        dfs(i + 1, j, val, map[i][j]);
        dfs(i, j + 1, val, map[i][j]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    dfs(0, 0, map[0][0] - '0', 0);
    cout << maxv << ' ' << minv;
}