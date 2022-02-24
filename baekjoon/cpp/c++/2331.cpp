#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1000;
int d[SIZE];

int calc(int n, int p)
{
    int sum = 0;
    while (n)
    {
        int rm = n % 10;
        int temp = 1;
        for (int i = 0; i < p; i++)
            temp *= rm;

        sum += temp;
        n /= 10;
    }
    return sum;
}
bool find(int num, int size, int &idx)
{
    for (int i = 0; i < size; i++)
    {
        if (d[i] == num)
        {
            idx = i;
            return true;
        }
    }
    return false;
}

int main()
{
    int a, p, cycleidx;
    scanf("%d %d", &a, &p);

    d[0] = a;
    for (int i = 1; i < SIZE; i++)
    {
        d[i] = calc(d[i - 1], p);
        if (find(d[i], i - 1, cycleidx))
        {
            printf("%d", cycleidx);
            return 0;
        }
    }
}