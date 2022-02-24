#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll maxprofit(int n, int m, int *sal)
{
    ll sum = 0, maxsum = 0, sidx = 0, eidx = m - 1;
    for (int i = 0; i <= eidx; i++)
        sum += sal[i];

    maxsum = sum;
    while (eidx < n)
    {
        sum = sum - sal[sidx++] + sal[++eidx];
        if (maxsum < sum)
            maxsum = sum;
    }
    return maxsum;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int *salary = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", salary + i);

    printf("%lld", maxprofit(n, m, salary));
}