#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int tarr[500000];

//시간 초과를 회피하기 위해 병합 정렬 수행
//swap만 잘 세면 되니까..

ll ans = 0;
void merge_sort(int *arr, int l, int r)
{
    if (r <= l)
    {
        return;
    }
    if (l + 1 == r)
    {
        if (arr[l] > arr[r])
        {
            int temp = arr[r];
            arr[r] = arr[l];
            arr[l] = temp;
            ans++;
        }
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
            ans += (mid - lidx + 1);
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
    cout << ans;
}