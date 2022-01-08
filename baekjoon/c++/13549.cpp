#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // time, position
bool visit[100001];

bool isin(int n)
{
    return 0 <= n && n <= 100000;
}
void push_if(priority_queue<pii, vector<pii>, greater<pii>> &pq, int pos, int time)
{
    if (isin(pos) && !visit[pos])
    {
        visit[pos] = true;
        pq.push({time, pos});
    }
}
int ans(int &n, int &k)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    visit[n] = true;
    pq.push({0, n});
    while (!pq.empty())
    {
        pii top = pq.top();
        pq.pop();
        int &time = top.first, &pos = top.second;
        if (pos == k)
            return time;

        push_if(pq, pos * 2, time);
        push_if(pq, pos - 1, time + 1);
        push_if(pq, pos + 1, time + 1);
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    cout << ans(n, k);
}