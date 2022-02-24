#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> div;
    for (int i = 1; i <= (int)sqrt(n); i++)
    {
        if (n % i == 0)
        {
            div.push_back(i);
            if (i * i != n)
                div.push_back(n / i);
        }
    }
    sort(div.begin(), div.end());
    if (div.size() < k)
        cout << 0;
    else
        cout << div[k - 1];
}