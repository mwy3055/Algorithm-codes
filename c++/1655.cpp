#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int> small;                            // �߾Ӱ����� �۰ų� ���� ��
    priority_queue<int, vector<int>, greater<int>> large; // �߾Ӱ����� ū ��

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
            if (2 <= small.size() - large.size()) // ���� ������ �����.
            {                                     // ���ذ��� ����Ͽ�, small�� large���� �� �� �� ���� ���� �ȴ�.
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