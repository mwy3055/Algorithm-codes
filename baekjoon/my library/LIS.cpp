#include <bits/stdc++.h>

int LIS(std::vector<int> &arr) //길이 n인 배열 arr에서 LIS의 길이를 구하여 반환
{
    int n = arr.size(), len = 0;
    std::vector<int> d(n);

    d[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (d[len] < arr[i])
        {
            d[++len] = arr[i];
        }
        else
        {
            auto ith = std::lower_bound(d.begin(), d.begin() + len, arr[i]) - d.begin();
            d[ith] = arr[i];
        }
    }

    return len + 1;
}