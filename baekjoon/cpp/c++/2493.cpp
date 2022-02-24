#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    stack<int> s;
    cin >> n;
    int *num = new int[n + 1], *ans = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        if (s.empty())
            s.push(i);
        else if (num[s.top()] < num[i])
        {
            while (!s.empty() && num[s.top()] < num[i])
            {
                int &t = s.top();
                s.pop();
                ans[t] = s.empty() ? 0 : s.top();
            }
            s.push(i);
        }
        else
            s.push(i);
    }
    while (!s.empty())
    {
        int &t = s.top();
        s.pop();
        ans[t] = s.empty() ? 0 : s.top();
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    delete[] num;
    delete[] ans;
}