#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    // preprocess
    int a[1001] = {1, 1};
    for (int i = 2; i <= 1000; i++)
    {
        for (int val = 1;; val++)
        {
            bool condition = true;
            for (int k = 1; i - 2 * k >= 0; k++)
            {
                if (val - a[i - k] == a[i - k] - a[i - 2 * k])
                {
                    condition = false;
                    break;
                }
            }
            if (condition)
            {
                a[i] = val;
                break;
            }
        }
    }

    int n;
    std::cin >> n;
    std::cout << a[n] << '\n';
}