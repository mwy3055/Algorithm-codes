#include <stdio.h>

int main()
{
    int cur = 0, maxv = 0;
    for (int i = 0; i < 10; i++)
    {
        int toff, ton;
        scanf("%d %d", &toff, &ton);
        cur = cur - toff + ton;
        if (maxv < cur)
            maxv = cur;
    }
    printf("%d", maxv);
}