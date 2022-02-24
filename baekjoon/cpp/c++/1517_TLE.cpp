#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int num[n];
    for (int i = 0; i < n; i++)
        cin >> num[i];

    bool sorted = false;
    ll cnt = 0;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (num[i] > num[i + 1])
            {
                int temp = num[i];
                num[i] = num[i + 1];
                num[i + 1] = temp;
                sorted = false;
                cnt++;
            }
        }
    }

    cout << cnt;
}