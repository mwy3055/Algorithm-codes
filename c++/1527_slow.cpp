#include <bits/stdc++.h>
using namespace std;

const int DIV = 10000000;
int arr[] = {1, 40000000, 70000000, 440000000, 470000000, 740000000, 770000000};

bool check(int n)
{
    if (n == 0)
        return false;
    while (n)
    {
        if (n % 10 != 4 && n % 10 != 7)
            return false;
        n /= 10;
    }
    return true;
}

int solve_min(int a, int b)
{
    int ans = 0;
    for (int i = a; i <= b; i++)
    {
        if (check(i))
            ans++;
    }
    return ans;
}
int solve(int a, int b)
{
    int ans = 0, cur = a, right;
    for (int i = 0; i < 7; i++)
    {
        if (arr[i] + 10000000 < a)
            continue;
        if (b < arr[i])
            break;
        for (int cur = max(arr[i], a); cur <= min(b, arr[i] + 10000000); cur++)
        {
            if (check(cur))
                ans++;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    if (b - a <= DIV)
        cout << solve_min(a, b);
    else
        cout << solve(a, b);
}