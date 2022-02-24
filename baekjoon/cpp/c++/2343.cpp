#include <bits/stdc++.h>

// 레슨을 m개로 나눴을 때, 나눈 부분의 합의 최댓값이 mid보다 작게 나눌 수 있을까?
bool divide(std::vector<int> &l, int &n, int m, int mid)
{
    int i = 0;
    while (i < n && m > 0)
    {
        int cidx = i, csum = l[i];
        if (mid < csum)
            return false;
        while (cidx + 1 <= n - m && csum + l[cidx + 1] <= mid)
        {
            csum += l[++cidx];
        }
        i = cidx + 1;
        m--;
    }
    return i == n && m == 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, l = 10000, r = 0; // [l, r]
    std::cin >> n >> m;
    std::vector<int> lessons(n);
    for (auto &minute : lessons)
    {
        std::cin >> minute;
        l = std::min(l, minute);
        r += minute;
    }

    while (l < r)
    {
        int mid = (l + r) / 2;
        if (divide(lessons, n, m, mid))
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << l; // what?
}