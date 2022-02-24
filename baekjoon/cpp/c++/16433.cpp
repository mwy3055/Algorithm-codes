#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, r, c;
    cin >> n >> r >> c;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ((i + j) % 2 == (r + c) % 2 ? 'v' : '.'); //예제 1 참고
        }
        cout << '\n';
    }
}