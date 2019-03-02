#include <iostream>
using namespace std;

int sum[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        sum[i] = sum[i - 1] + t;
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << sum[e] - sum[s - 1] << '\n';
    }
}