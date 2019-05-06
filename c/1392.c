#include <stdio.h>

int main()
{
    int t[10000], n, q, tidx = 0;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        int b;
        scanf("%d", &b);
        for (int j = 0; j < b; j++)
            t[tidx++] = i + 1;
    }

    for (int i = 0; i < q; i++)
    {
        int ti;
        scanf("%d", &ti);
        printf("%d\n", t[ti]);
    }
}