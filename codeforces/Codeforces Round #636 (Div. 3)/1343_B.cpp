#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 4)
        {
            cout << "NO" << '\n';
            continue;
        }

        vector<int> first, second;
        int evensum = 0, oddsum = 0;
        for (int i = 2; i <= n; i += 2)
        {
            first.push_back(i);
            evensum += i;
        }
        for (int i = 1; i <= n - 3; i += 2)
        {
            second.push_back(i);
            oddsum += i;
        }
        if ((evensum - oddsum) % 2 == 0)
        {
            cout << "NO" << '\n';
            continue;
        }
        second.push_back(evensum - oddsum);

        cout << "YES" << '\n';
        for (auto &f : first)
            cout << f << ' ';
        for (auto &s : second)
            cout << s << ' ';
        cout << '\n';
    }
}