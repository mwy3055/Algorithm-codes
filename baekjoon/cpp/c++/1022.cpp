#include <bits/stdc++.h>

int r1, c1, r2, c2;

void getinput()
{
    std::cin >> r1 >> c1 >> r2 >> c2;
}

int gettype(int r, int c)
{
    int d = std::max(std::abs(r), std::abs(c));
    int type;
    if (r == d && c > -d)
    {
        type = 3;
    }
    else if (c == -d && r > -d)
    {
        type = 2;
    }
    else if (r == -d && c < d)
    {
        type = 1;
    }
    else if (c == d && r < d)
    {
        type = 0;
    }
    else
    {
        exit(-1);
    }
    return type;
}

int getbase(int r, int c, int type)
{
    int d = std::max(std::abs(r), std::abs(c));
    return 4 * d * d - 4 * d + 2 + (type * 2 * d);
}

int getres(int r, int c, int type)
{
    int d = std::max(std::abs(r), std::abs(c));
    if (type == 3)
        return c + (d - 1);
    else if (type == 2)
        return r + (d - 1);
    else if (type == 1)
        return (d - 1) - c;
    else if (type == 0)
        return (d - 1) - r;
    else
        exit(-1);
}

int getnum(int r, int c)
{
    if (r == 0 && c == 0)
        return 1;

    int d = std::max(std::abs(r), std::abs(c));

    int type = gettype(r, c);
    int base = getbase(r, c, type);
    int residual = getres(r, c, type);
    return base + residual;
}

int getlen(int n)
{
    int len = 0;
    while (n)
    {
        n /= 10;
        len++;
    }
    return len;
}

void solve()
{
    std::queue<int> q;
    int max_len = 0;

    for (int r = r1; r <= r2; r++)
    {
        for (int c = c1; c <= c2; c++)
        {
            auto n = getnum(r, c);
            q.push(n);
            max_len = std::max(max_len, getlen(n));
        }
    }

    for (int r = r1; r <= r2; r++)
    {
        for (int c = c1; c <= c2; c++)
        {
            std::cout.width(max_len);
            std::cout.fill(' ');
            std::cout << q.front() << ' ';
            q.pop();
        }
        std::cout << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}