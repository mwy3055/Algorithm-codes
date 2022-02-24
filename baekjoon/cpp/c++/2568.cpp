#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int n;
vector<pii> lines;
int track[100000];

int solve()
{
    int len = 1;
    vector<int> d;

    d.push_back(lines[0].second);
    for (int i = 1; i < n; i++)
    {
        int j = lower_bound(d.begin(), d.end(), lines[i].second) - d.begin();
        if (j == len)
        {
            d.push_back(lines[i].second);
            track[i] = len++;
        }
        else
        {
            d[j] = lines[i].second;
            track[i] = j;
        }
    }
    return len;
}
void print(int &len)
{
    set<int> s;
    int cidx = n - 1, clen = len - 1;
    while (0 <= cidx && track[cidx] != clen)
        cidx--;
    do
    {
        s.insert(lines[cidx].first);
        if (--clen < 0)
            break;
        while (0 <= cidx && track[cidx] != clen)
            cidx--;
    } while (0 <= cidx);

    cout << n - len << '\n';
    for (auto &line : lines)
    {
        if (s.find(line.first) == s.end())
            cout << line.first << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        lines.push_back({a, b});
    }
    sort(lines.begin(), lines.end());

    int len = solve();
    print(len);
}