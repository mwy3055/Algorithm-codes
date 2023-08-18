#include <stdio.h>
void lis(int n, int *ar)
{
    int len = 1, i, d[1000] = {0};
    d[0] = ar[0];
    for (i = 1; i < n; i++)
    {
        int j = 0;
        while (d[j] < ar[i] && d[j] != 0)
            j++;
        if (j == len)
            d[len++] = ar[i];
        else
            d[j] = ar[i];
    }
    printf("%d", len);
}
int main()
{
    int n, i, ar[1000];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", ar + i);
    }
    lis(n, ar);
}