#include <stdio.h>

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i <= 30; i++)
    {
        cnt += (n & (1 << i)) != 0;
    }
    printf("%d", cnt == 1);
}