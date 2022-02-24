#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Query = pair<int, int>;

int arr[40], n, s;
ll query[8000001], temp[8000001];

bool vaild(ll n)
{
    return 0 <= n;
}
//참고 링크: https://en.wikipedia.org/wiki/Subset_sum_problem#Pseudo-polynomial_time_dynamic_programming_solution
ll solve()
{
    int A = 0, B = 0, idx = 0;
    while (arr[idx] < 0)
        A += arr[idx++];
    while (idx < n)
        B += arr[idx++];

    for (int i = A; i <= B; i++)
        query[i - A] = (arr[0] == i);

    for (int i = 1; i < n; i++)
    {
        for (int t = A; t <= B; t++)
        {
            temp[t - A] = query[t - A] + (vaild(t - A - arr[i]) ? query[t - A - arr[i]] : 0) + (arr[i] == t);
        }
        memcpy(query, temp, sizeof(ll) * (B - A + 1));
    }

    return query[s - A];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    cout << solve();
}