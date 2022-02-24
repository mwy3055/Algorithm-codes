#include <stdio.h>

void solve()
{
    int n;
    scanf("%d", &n);
    int sumc = 0;
    double sumg = 0;
    for (int i = 0; i < n; i++)
    {
        int c;
        double g;
        scanf("%d %lf", &c, &g);
        sumc += c;
        sumg += g * c;
    }
    printf("%d %.1f\n", sumc, sumg / sumc);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}