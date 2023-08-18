#include <iostream>
#include <string>
using namespace std;

int n;
char map[65][65];

bool allzero(int &y, int &x, int &size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (map[y + i][x + j] == '1')
                return false;
    return true;
}

bool allone(int &y, int &x, int &size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (map[y + i][x + j] == '0')
                return false;
    return true;
}

string div(int y, int x, int size)
{
    if (allzero(y, x, size))
        return "0";
    else if (allone(y, x, size))
        return "1";

    int ns = size / 2;
    return "(" + div(y, x, ns) + div(y, x + ns, ns) + div(y + ns, x, ns) + div(y + ns, x + ns, ns) + ")";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];

    cout << div(1, 1, n);
}