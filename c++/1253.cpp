#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, num[2000];

bool two_pointer(int idx)
{
    ll s = 0, e = 0, sum = num[0], ans = num[idx];
    if (idx == 0)
    {
        s = e = 1;
        sum = num[1];
    }
    while (s < n)
    {
        if (ans <= sum)
        {
            sum -= num[s++];
            if (s == idx)
                s++;
        }
        else if (e == n - 1)
            break;
        else
        {
            if (e + 1 == idx)
                e++;
            sum += num[++e];
        }
        if (sum == ans)
            return true;
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

    int ans = 0;
    for (int i = 0; i < n; i++) //i번째 수를 만들 수 있는지?
    {
        if (two_pointer(i))
            ans++;
    }
    cout << ans;
}