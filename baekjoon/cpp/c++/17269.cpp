#include <bits/stdc++.h>
using namespace std;

void make_data(map<char, int> &m)
{
    int arr[] = {3, 2, 1, 2, 4,
                 3, 1, 3, 1, 1,
                 3, 1, 3, 2, 1,
                 2, 2, 2, 1, 2,
                 1, 1, 1, 2, 2,
                 1};
    for (int i = 0; i < 26; i++)
        m['A' + i] = arr[i];
}

int solve(int &n, int &m, string &A, string &B)
{
    map<char, int> mapping;
    make_data(mapping);

    int arr[n + m];
    int ai = 0, bi = 0, idx = 0;
    while (ai < n && bi < m)
    {
        arr[idx++] = mapping[A[ai++]];
        arr[idx++] = mapping[B[bi++]];
    }
    if (ai == n)
        while (bi < m)
            arr[idx++] = mapping[B[bi++]];
    else
        while (ai < n)
            arr[idx++] = mapping[A[ai++]];

    for (int i = n + m - 1; 2 <= i; i--)
    {
        int temp[i];
        for (int j = 0; j < i; j++)
            temp[j] = (arr[j + 1] + arr[j]) % 10;
        memcpy(arr, temp, sizeof(int) * i);
    }

    return arr[0] * 10 + arr[1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    string A, B;
    cin >> n >> m >> A >> B;
    cout << solve(n, m, A, B) << '%';
}