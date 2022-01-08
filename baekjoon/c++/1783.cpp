#include <cstdio>
using namespace std;

int main()
{
    int n, m, ans; //세로, 가로
    scanf("%d %d", &n, &m);
    if (3 <= n)
    {
        if (m <= 4)
            ans = m;
        else if (m <= 6)
            ans = 4;
        else
            ans = m - 2;
    }
    else if (n == 2)
    {
        if (m <= 2)
            ans = 1;
        else if (m <= 6)
            ans = m - m / 2;
        else
            ans = 4;
    }
    else
        ans = 1;
    printf("%d", ans);
}