#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (next_permutation(arr, arr + n))
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    else
        cout << -1;
        
}