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
    ll s, e, sum, ans = num[idx];

    search_start(s, e, sum, idx);
    while (s < n)
    {
        if (ans < sum)
        {
            break;
        }
        else if (e == n - 1)
        {
            break;
        }
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