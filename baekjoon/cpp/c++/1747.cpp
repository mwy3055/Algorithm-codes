#include <bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
    if (n == 1)
        return false;

    int sq = (int)sqrt(n);
    for (int i = 2; i <= sq; i++)
        if (n % i == 0)
            return false;
    return true;
}
bool ispalin(int n)
{
    string s = to_string(n);
    int len = s.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i = n;; i++)
    {
        if (ispalin(i) && isprime(i))
        {
            cout << i;
            return 0;
        }
    }
}