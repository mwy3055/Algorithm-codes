#include <bits/stdc++.h>
using namespace std;

string arr[50];
bool nsquare(int &i, int &j, int &size)
{
    return arr[i][j] == arr[i + size - 1][j] && arr[i][j] == arr[i][j + size - 1] && arr[i][j] == arr[i + size - 1][j + size - 1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maxs = max(n, m), ans = 0;
    for (int s = 1; s <= maxs; s++)
    {
        for (int i = 0; i <= n - s; i++)
        {
            for (int j = 0; j <= m - s; j++)
            {
                if (nsquare(i, j, s))
                    ans = s;
            }
        }
    }
    cout << ans * ans;
}