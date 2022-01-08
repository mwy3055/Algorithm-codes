#include <bits/stdc++.h>
using namespace std;

bool solve(int &a, int &b, int &c, int &n)
{
    for (int i = 0; i * c <= n; i++)
    {
        for (int j = 0; i * c + j * b <= n; j++)
        {
            for (int k = 0; i * c + j * b + k * a <= n; k++)
            {
                if (n == i * c + j * b + k * a)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    cout << solve(a, b, c, n);
}