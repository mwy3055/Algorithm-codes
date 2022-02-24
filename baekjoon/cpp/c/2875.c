#include <stdio.h>

int main()
{
    int n, m, k, cnt = 0;
    scanf("%d %d %d", &n, &m, &k);
    while (n - 2 >= 0 && m - 1 >= 0 && n + m - 3 >= k)
    {
        n -= 2;
        m -= 1;
        cnt++;
    }
    printf("%d", cnt);
}