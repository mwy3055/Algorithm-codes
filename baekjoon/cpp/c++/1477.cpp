#include <bits/stdc++.h>

using vi = std::vector<int>;

bool can_divide(vi &diff, int m, int l, int mid)
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

    // 입력받기
    // 고속도로의 시작, 끝 지점도 휴게소로 간주 (비어있는 거리 계산을 위해)
    int n, m, l;
    std::cin >> n >> m >> l;
    vi rest;
    for (int i = 0; i < n; i++)
    {
        int loc;
        std::cin >> loc;
        rest.push_back(loc);
    }
    rest.push_back(0);
    rest.push_back(l);
    std::sort(rest.begin(), rest.end());

    // 휴게소가 없는 구간의 길이 계산
    vi diff;
    for (int i = 0; i < rest.size() - 1; i++)
        diff.push_back(rest[i + 1] - rest[i]);

    // 휴게소의 최대 간격을 이분 탐색
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