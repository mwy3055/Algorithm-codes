#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int> small;                            // 중앙값보다 작거나 같은 값
    priority_queue<int, vector<int>, greater<int>> large; // 중앙값보다 큰 값

    int n, input;
    cin >> n;

    cin >> input;
    cout << input << '\n';
    small.push(input);
    n--;

    while (n--)
    {
        cin >> input;
        if (input <= small.top())
        {
            small.push(input);
            if (2 <= small.size() - large.size()) // 힙의 균형을 맞춘다.
            {                                     // 기준값을 고려하여, small은 large보다 한 개 더 많이 들어가도 된다.
                int top = small.top();
                small.pop();
                large.push(top);
            }
        }
        else
        {
            large.push(input);
            if (1 <= large.size() - small.size())
            {
                int top = large.top();
                large.pop();
                small.push(top);
            }
        }
        cout << small.top() << '\n';
    }
}