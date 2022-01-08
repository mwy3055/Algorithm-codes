#include <bits/stdc++.h>
using namespace std;

typedef vector<int>::iterator viit;
int ans1, ans2, sum;

void compare(vector<int> &v, int &value, viit it)
{
    if (it < v.end() && *it != value && abs(value + *it) < abs(sum))
    {
        ans1 = value, ans2 = *it;
        sum = ans1 + ans2;
    }
    if (v.begin() <= (it - 1) && (it - 1) < v.end() && *(it - 1) != value && abs(value + *(it - 1)) < abs(sum))
    {
        ans1 = value, ans2 = *(it - 1);
        sum = ans1 + ans2;
    }
    if ((it + 1) < v.end() && *(it + 1) != value && abs(value + *(it + 1)) < abs(sum))
    {
        ans1 = value, ans2 = *(it + 1);
        sum = ans1 + ans2;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    ans1 = v[0], ans2 = v[1];
    sum = ans1 + ans2;
    for (auto &value : v)
    {
        viit it = lower_bound(v.begin(), v.end(), -value);
        compare(v, value, it);
        it = upper_bound(v.begin(), v.end(), -value);
        compare(v, value, it);
    }

    if (ans1 > ans2)
        swap(ans1, ans2);
    cout << ans1 << ' ' << ans2;
}