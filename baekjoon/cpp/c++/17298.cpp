#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; //num, index

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n), nge(n, -1);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    stack<pii> s;
    s.push(make_pair(nums[0], 0));
    for (int i = 1; i < n; i++)
    {
        int &cur = nums[i];
        while (!s.empty() && s.top().first < cur)
        {
            pii top = s.top();
            s.pop();
            nge[top.second] = cur;
        }
        s.push(make_pair(cur, i));
    }

    for (int i = 0; i < n; i++)
        cout << nge[i] << ' ';
}