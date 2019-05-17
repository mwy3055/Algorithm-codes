#include <bits/stdc++.h>
using namespace std;

int LIS(int &n, int *arr) //길이 n인 배열 arr에서 LIS의 길이를 구하여 반환
{
    int len = 0;
    int *d = new int[n];

    d[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (d[len] < arr[i])
        {
            d[++len] = arr[i];
        }
        else
        {
            int ith = lower_bound(d, d + len, arr[i]) - d;
            d[ith] = arr[i];
        }
    }

    delete[] d;
    return len + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << LIS(n, arr);
    delete[] arr;
}