#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int* num = new int[n];
    for(int i = 0; i < n; i++)
        num[i] = i + 1;

    do {
        for (int i = 0; i < n; i++)
            cout << num[i] << ' ';
        cout << '\n';
    } while(next_permutation(num, num + n));




    delete[] num;
}