#include <bits/stdc++.h>

bool can_divide(std::vector<int> &diff, int m, int l, int mid)
{
    int cnt = 0; // 최대 간격이 mid일 때 세워야 하는 휴게소의 최소 개수
    for (auto &d : diff)
    {
        cnt += (d - 1) / mid;
    }
    return cnt <= m;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, l;
    std::cin >> n >> m >> l;
    std::vector<int> rest(n);
    for (auto &r : rest)
        std::cin >> r;
    std::sort(rest.begin(), rest.end());

    std::vector<int> diff;
    if (rest[0] != 0)
        diff.push_back(rest[0]);
    for (int i = 0; i < rest.size() - 1; i++)
        diff.push_back(rest[i + 1] - rest[i]);
    if (rest.back() != l - 1)
        diff.push_back(l - 1 - rest.back());
    std::sort(diff.begin(), diff.end());

    int left = 1, right = l; // [left, right]
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (can_divide(diff, m, l, mid))
            right = mid;
        else
            left = mid + 1;
    }
    std::cout << left;
}