#include <bits/stdc++.h>
using namespace std;

int tarr[50000];

void merge_sort(int *arr, int l, int r)
{
    if (r <= l)
    {
        return;
    }

    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    /* merge */
    int lidx = l, ridx = mid + 1, tidx = 0;
    while (lidx <= mid && ridx <= r)
    {
        if (arr[lidx] <= arr[ridx])
        {
            tarr[tidx++] = arr[lidx++];
        }
        else
        {
            tarr[tidx++] = arr[ridx++];
        }
    }

    if (r < ridx)
    {
        while (lidx <= mid)
            tarr[tidx++] = arr[lidx++];
    }
    else
    {
        while (ridx <= r)
            tarr[tidx++] = arr[ridx++];
    }

    memcpy(arr + l, tarr, sizeof(int) * (r - l + 1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int num[n];
    for (int i = 0; i < n; i++)
        cin >> num[i];

    merge_sort(num, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << num[i] << ' ';
}