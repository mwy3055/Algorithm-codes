#include <bits/stdc++.h>
using namespace std;

double d(int x1, int y1, int x2, int y2)
{
    int dx = x1 - x2, dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int dist(int *x, int *y, int *arr)
{
    double dsum = d(x[0], y[0], x[arr[0]], y[arr[0]]);
    for (int i = 0; i < 2; i++)
        dsum += d(x[arr[i]], y[arr[i]], x[arr[i + 1]], y[arr[i + 1]]);
    return (int)dsum;
}

int main()
{
    int x[4], y[4];
    for (int i = 0; i < 4; i++)
        scanf("%d %d", x + i, y + i);

    int arr[] = {1, 2, 3}, ans = 0x4fffffff;
    do
    {
        ans = min(ans, dist(x, y, arr));
    } while (next_permutation(arr, arr + 3));

    printf("%d", ans);
}