#include <bits/stdc++.h>

using pii = std::pair<int, int>;

int n, d[][2] = {{-1, 0}, {0, 1}, {0, -1}};
bool board[1000][1000]; // true: black, false: white

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << (board[i][j] ? '#' : '.');
        }
        std::cout << '\n';
    }
}

void getinput()
{
    std::string s;
    std::cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        board[0][i] = (s[i] == '#');
    }
}

bool isin(int r, int c)
{
    return 0 <= r && r < n && 0 <= c && c < n;
}

int search(int r, int c)
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        auto nr = r + d[i][0], nc = c + d[i][1];
        if (isin(nr, nc) && board[nr][nc])
        {
            count++;
        }
    }
    return count;
}

void solve()
{
    for (int i = 0; i < n - 1; i++)
    {
        // i-th row is complete, so make (i+1)-th row
        for (int j = 0; j < n; j++)
        {
            // see previous and current row
            auto count = search(i, j);
            board[i + 1][j] = (count % 2);
        }
    }
    print();
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}