//https://www.acmicpc.net/blog/view/27
#include <stdio.h>

int ccw(int *x, int *y)
{
    return (x[1] - x[0]) * (y[2] - y[0]) - (y[1] - y[0]) * (x[2] - x[0]);
}

int main()
{
    int x[3], y[3];
    for (int i = 0; i < 3; i++)
        scanf("%d %d", x + i, y + i);

    int ans = ccw(x, y);
    if (ans > 0)
        printf("1");
    else if (ans < 0)
        printf("-1");
    else
        printf("0");
}