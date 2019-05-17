#include <bits/stdc++.h>
using namespace std;

int LIS(int &n, int *arr) //���� n�� �迭 arr���� LIS�� ���̸� ���Ͽ� ��ȯ
{
    int len = 0;
    int *d = new int[n];

    d[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (d[len] < a[i])
        {
            d[++len] = a[i];
        }
        else
        {
            ith = lower_bound(d, d + len, a[i]) - d;
            d[ith] = a[i];
        }
    }

    delete[] d;
    return len + 1;
}