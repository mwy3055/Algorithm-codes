#include <iostream>
using namespace std;

int org[20], n;
bool avail[2000001];

void dfs(int i, int sum, bool nullset)
{
    if (i == n)
    {
        if (nullset)
            avail[sum] = true;
        return;
    }

    dfs(i + 1, sum + org[i], nullset | true);
    dfs(i + 1, sum, nullset);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> org[i];
        sum += org[i];
    }

    dfs(0, 0, false);
    for (int i = 1; i <= sum; i++)
    {
        if (!avail[i])
        {
            cout << i;
            return 0;
        }
    }
    cout << sum + 1;
}