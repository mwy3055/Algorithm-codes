#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> package(m), each(m);
    for (int i = 0; i < m; i++)
        cin >> package[i] >> each[i];

    sort(package.begin(), package.end());
    sort(each.begin(), each.end());

    if (package[0] < 6 * each[0])
    {
        //패키지로 많이 삼
        cout << package[0] * (n / 6) + min(package[0], each[0] * (n % 6));
    }
    else
    {
        cout << each[0] * n;
    }
}