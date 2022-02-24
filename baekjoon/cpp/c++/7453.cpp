#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//map은 느려서 못 쓴다고 함..
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int A[n], B[n], C[n], D[n];
    for (int i = 0; i < n; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];

    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v1.push_back(A[i] + B[j]);
            v2.push_back(C[i] + D[j]);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    ll ans = 0;
    for (auto &n : v1)
    {
        auto pi = equal_range(v2.begin(), v2.end(), -n);
        ans += pi.second - pi.first;
    }
    cout << ans;
}