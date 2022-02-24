#include <bits/stdc++.h>
using namespace std;

// n - (largest aliquot of n)
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> div;
    for (int i = 2; i <= sqrt(n) + 1; i++)
    {
        if (n % i == 0)
        {
            div.push_back(i);
            div.push_back(n / i);
        }
    }
    div.push_back(1);
    sort(div.begin(), div.end());
    cout << n - div.back();
}