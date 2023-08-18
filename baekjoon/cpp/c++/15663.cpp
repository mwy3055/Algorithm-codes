#include <bits/stdc++.h>
using namespace std;

string gethash(int *num, int &m)
{
    stringstream ss;
    for (int i = 0; i < m; i++)
    {
        int x = num[i];
        do
        {
            ss << x % 10;
            x /= 10;
        } while (x > 0);
        if (i != m - 1)
            ss << '-';
    }
    return ss.str();
}

int main()
{
    int num[8];
    set<string> s;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);

    do
    {
        auto hash = gethash(num, m);
        if (s.find(hash) == s.end())
        {
            for (int i = 0; i < m; i++)
                cout << num[i] << ' ';
            cout << '\n';
            s.insert(hash);
        }
    } while (next_permutation(num, num + n));
}