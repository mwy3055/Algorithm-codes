#include <stdio.h>

int main()
{
    int n, pscore = 1, sum = 0;
    scanf("%d", &n);
    while (n--)
    {
        int t;
        scanf("%d", &t);
        if (t)
        {
            sum += pscore++;
        }
        else
        {
            pscore = 1;
        }
    }

    printf("%d", sum);
}