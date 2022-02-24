#include <bits/stdc++.h>
using namespace std;

int arr[8];
bool selected[8];

int factorial(int n)
{
    int rtn = 1;
    for (int i = 2; i <= n; i++)
        rtn *= i;
    return rtn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    int redund = factorial(n - m), idx = 1;
    do
    {
        if (idx % redund == 0)
        {
            for (int i = 0; i < m; i++)
                cout << arr[i] << ' ';
            cout << '\n';
            idx = 1;
        }
        else
            idx++;
    } while (next_permutation(arr, arr + n));
}