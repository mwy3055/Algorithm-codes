#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, val[1000], jump[1000];
    memset(jump, -1, 1000 * sizeof(int));
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> val[i];

    jump[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= val[i]; j++)
        {
            if (jump[i] == -1)
                break;

            if (i + j < n)
            {
                jump[i + j] = (jump[i + j] == -1) ? jump[i] + 1 : min(jump[i + j], jump[i] + 1);
            }
        }
    }

    cout << jump[n - 1];
}