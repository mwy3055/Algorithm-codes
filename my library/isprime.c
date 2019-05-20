#include <math.h>

int isprime(int n)
{
    int sq = (int)sqrt(n);
    for (int i = 2; i <= sq; i++)
        if (n % i == 0)
            return 0;
    return 1;
}