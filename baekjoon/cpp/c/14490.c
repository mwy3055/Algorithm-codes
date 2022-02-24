#include <stdio.h>

int GCD(int a, int b)
{
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b % a)
        return GCD(a, b % a);
    else
        return a;
}

int main()
{
    int n, m;
    scanf("%d:%d", &n, &m);
    int gcd = GCD(n, m);
    printf("%d:%d", n / gcd, m / gcd);
}