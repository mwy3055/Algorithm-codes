#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int n, l;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l;

    int midx = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++)
    {
        int s = i - l + 1, t;
        if (s < 0)
            s = 0;
        cin >> t;
        pq.push({t, i});
        while (!(s <= pq.top().second && pq.top().second <= i))
            pq.pop();
        cout << pq.top().first << ' ';
    }
}