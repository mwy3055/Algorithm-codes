#include <stdio.h>
typedef long long ll;

ll GCD(ll a, ll b)
{
    if (a > b)
    {
        ll temp = a;
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
    ll a, b;
    scanf("%lld %lld", &a, &b);

    ll gcd = GCD(a, b);
    for (int i = 0; i < gcd; i++)
        printf("1");
}