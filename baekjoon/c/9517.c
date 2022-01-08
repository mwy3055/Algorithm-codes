#include <stdio.h>

int main()
{
    int k, n;
    scanf("%d %d", &k, &n);

    int tlimit = 210;
    for (int i = 0; i < n; i++)
    {
        int t;
        char z;
        scanf("%d %c", &t, &z);

        tlimit -= t;
        if (tlimit <= 0)
            break;

        if (z == 'T')
            k = k % 8 + 1;
    }

    printf("%d", k);
}