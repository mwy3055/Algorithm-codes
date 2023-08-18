#include <bits/stdc++.h>

using namespace std;

int n;
char base[3][6] =
    {"  *  ",
     " * * ",
     "*****"};

//1024 *3 , 1024 * 6
char board[3200][6400];

void solve(int n, int y, int x)
{
    if (n == 1)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 5; j++)
                board[y + i][x + j] = base[i][j];
        return;
    }

    solve(n / 2, y, x + 3 * n / 2);
    solve(n / 2, y + 3 * n / 2, x);
    solve(n / 2, y + 3 * n / 2, x + 3 * n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    solve(n / 3, 0, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            if (board[i][j] == '*')
                cout << '*';
            else
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
