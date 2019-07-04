#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, num[2000];

void search_start(int &s, int &e, int &sum, int &idx)
{
    if (idx == 0)
        s = 1, e = 2;
    else if (idx == 1)
        s = 0, e = 2;
    else
        s = 0, e = 1;

    sum = num[s] + num[e];
}
bool two_pointer(int idx) //how?
{
    ll s = 0, e = n - 1, ans = num[idx];
    if (s == idx)
        s++;
    if (e == idx)
        e--;

    while (s < e)
    {
        if (num[s] + num[e] == ans)
            return true;
        else if (num[s] + num[e] < ans)
        {
            s++;
            if (s == idx)
                s++;
        }
        else
        {
            e--;
            if (e == idx)
                e--;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    sort(num, num + n);

    int ans = 0;
    for (int i = 0; i < n; i++) //i번째 수를 만들 수 있는지?
    {
        if (two_pointer(i))
        {
            cout << num[i] << '\n';
            ans++;
        }
    }
    cout << ans;
}