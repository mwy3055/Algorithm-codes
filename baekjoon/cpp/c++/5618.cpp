#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b % a)
        return GCD(a, b % a);
    else
        return a;
}

int main()
{
    int n, num[3], gcd;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    gcd = num[0];
    for (int i = 1; i < n; i++)
        gcd = GCD(gcd, num[i]);

    vector<int> gcds;
    for (int i = 1; i <= (int)sqrt(gcd); i++)
    {
        if (gcd % i == 0)
        {
            gcds.push_back(i);
            if (i != gcd / i)
                gcds.push_back(gcd / i);
        }
    }
    sort(gcds.begin(), gcds.end());
    for (int &g : gcds)
        cout << g << '\n';
}