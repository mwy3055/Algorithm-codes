#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int num[1001], idx = 1;
    for (int i = 1; idx <= 1000; i++)
    {
        for (int j = 0; j < i && idx <= 1000; j++)
        {
            num[idx++] = i;
        }
    }

    int a, b, sum = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        sum += num[i];
    }
    cout << sum;
}