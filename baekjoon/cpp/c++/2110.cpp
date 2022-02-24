#include <bits/stdc++.h>
using namespace std;

int n, c;

bool dist_available(int *coord, int dist)
{
    int cnt = 1, loc = coord[0];
    for (int idx = 1; idx < n; idx++)
    {
        if (dist <= coord[idx] - loc)
        {
            cnt++;
            loc = coord[idx];
        }
    }

    return c <= cnt;
}
int par_search(int *coord)
{
    int left = 1, right = coord[n - 1] - coord[0] + 1; //가능한 최소, 최대 간격
    int mid;
    while (left + 1 < right)
    {
        mid = (left + right) / 2;       //간격
        if (dist_available(coord, mid)) //이 간격이 가능한 경우
        {
            left = mid;
        }
        else //이 간격이 불가능한 경우
        {
            right = mid;
        }
    }
    return left;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;
    int coord[n];
    for (int i = 0; i < n; i++)
        cin >> coord[i];
    sort(coord, coord + n);

    cout << par_search(coord);
}