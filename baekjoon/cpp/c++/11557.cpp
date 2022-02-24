#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> Pair;

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
        vector<Pair> p;
        for (int i = 0; i < n; i++)
        {
            Pair temp;
            cin >> temp.second >> temp.first;
            p.push_back(temp);
        }
        sort(p.begin(), p.end(), greater<Pair>());
        cout << p[0].second << '\n';
    }
}