#include <bits/stdc++.h>

using namespace std;

int n;

long long multipleOfThree(int num, int sum, int length)
{
    if (length == 1 && sum % 3 == 0)

        return 1;

    else if (length == 1)

        return 0;

    long long result = 0;

    for (int i = 0; i <= 2; i++)

        result += multipleOfThree(i, sum + i, length - 1);

    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    if (n == 1)
        cout << 0 << "\n";
    else
    {
        long long result = 0;
        
        //0으로 시작할 수 없다
        for (int i = 1; i <= 2; i++)
            result += multipleOfThree(i, i, n);
        cout << result << "\n";
    }
    return 0;
}

