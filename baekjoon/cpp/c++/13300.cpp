#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, stud[2][7] = {0};
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int gen, grd;
        cin >> gen >> grd;
        stud[gen][grd]++;
    }

    int ans = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (stud[i][j] % k == 0)
                ans += stud[i][j] / k;
            else
                ans += stud[i][j] / k + 1;
        }
    }

    cout << ans;
}