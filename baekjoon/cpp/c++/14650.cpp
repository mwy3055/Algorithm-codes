#include <bits/stdc++.h>

using ll = long long;
ll ans;
int n;

void search(int num, int dep)
{
    if (dep == n)
    {
        if (num % 3 == 0)
            ans++;
        return;
    }
    search(num * 10, dep + 1);
    search(num * 10 + 1, dep + 1);
    search(num * 10 + 2, dep + 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    search(1, 1);
    search(2, 1);
    std::cout << ans << '\n';
}