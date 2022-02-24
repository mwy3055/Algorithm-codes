#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // {i, arr[i]}
int n, arr[1000];
vector<int> track(1000);

int solve()
{
    int len = 1;
    vector<int> d;

    d.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        int j = lower_bound(d.begin(), d.end(), arr[i]) - d.begin();
        if (j == len)
        {
            d.push_back(arr[i]);
            track[i] = len++;
        }
        else
        {
            d[j] = arr[i];
            track[i] = j;
        }
    }
    return len;
}
void print(int &len)
{
    stack<int> s;
    int cidx = n - 1, clen = len - 1;
    while (0 <= cidx && track[cidx] != clen)
        cidx--;
    do
    {
        s.push(arr[cidx]);
        clen--;
        if (clen < 0)
            break;
        while (0 <= cidx && track[cidx] != clen)
            cidx--;
    } while (0 <= cidx);

    cout << len << '\n';
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int len = solve();
    print(len);
}