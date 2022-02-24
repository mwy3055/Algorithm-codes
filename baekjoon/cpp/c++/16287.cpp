#include <bits/stdc++.h>

// n^2 두번으로 서로 다른 4개가 선택되도록 해 보자.
bool exist[800001];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int w, n;
    std::cin >> w >> n;
    std::vector<int> a(n);
    for (auto &elem : a)
        std::cin >> elem;

    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] < w && exist[w - a[i] - a[j]])
            {
                ans = true;
                break;
            }
        }
        for (int j = 0; j < i; j++)
        {
            exist[a[i] + a[j]] = true;
        }
    }
    std::cout << (ans ? "YES" : "NO") << '\n';
}