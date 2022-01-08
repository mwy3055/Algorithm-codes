#include <iostream>
using namespace std;

int n;

bool isprime(int num)
{
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}

void search(int num, int len)
{
    if (len == n && isprime(num))
    {
        cout << num << '\n';
        return;
    }

    int src[4] = {1, 3, 7, 9};
    if (isprime(num))
    {
        for (int i = 0; i < 4; i++)
        {
            search(num * 10 + src[i], len + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    search(2, 1);
    search(3, 1);
    search(5, 1);
    search(7, 1);
}