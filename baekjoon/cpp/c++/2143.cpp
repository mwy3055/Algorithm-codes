#include <bits/stdc++.h>
using namespace std;

int subsum[2][1001][1001];

void make_subsum(int which, int *array, int arrsiz)
{
    for (int i = 1; i <= arrsiz; i++)
        subsum[which][1][i] = subsum[which][1][i - 1] + array[i];

    for (int i = 2; i <= arrsiz; i++)
    {
        for (int j = i; j <= arrsiz; j++)
        {
            subsum[which][i][j] = subsum[which][1][j] - subsum[which][1][i - 1];
        }
    }
}
void collect_subsum(int which, vector<int> &all, int arrsiz)
{
    for (int i = 1; i <= arrsiz; i++)
    {
        for (int j = i; j <= arrsiz; j++)
        {
            all.push_back(subsum[which][i][j]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, m, a[1001], b[1001];
    cin >> t >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    make_subsum(0, a, n);
    make_subsum(1, b, m);

    vector<int> allsubsum[2];
    collect_subsum(0, allsubsum[0], n);
    collect_subsum(1, allsubsum[1], m);

    sort(allsubsum[0].begin(), allsubsum[0].end());
    sort(allsubsum[1].begin(), allsubsum[1].end());

    long long ans = 0;
    for (auto &a : allsubsum[0])
    {
        auto it = equal_range(allsubsum[1].begin(), allsubsum[1].end(), t - a);
        ans += it.second - it.first;
    }

    cout << ans;
}