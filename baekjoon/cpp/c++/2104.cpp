#include <bits/stdc++.h>

using ll = long long;

const int MAX = 100000;
int n, a[MAX + 1];
// [0, i] 구간의 합
ll subsum[MAX + 1];

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
}

void preprocess()
{
    subsum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        subsum[i] = subsum[i - 1] + a[i];
    }
}

// [left, right] 구간의 합
ll get_sum(int left, int right)
{
    if (left == 0)
        return subsum[right];
    return subsum[right] - subsum[left - 1];
}

// 히스토그램에서 가장 큰 직사각형
ll solve()
{
    ll ans = 0;
    // 스택에는 인덱스를 저장한다.
    std::stack<int> s;
    for (int i = 0; i <= n; i++)
    {
        while (!s.empty() && a[i] < a[s.top()])
        {
            ll height = a[s.top()];
            s.pop();
            // height보다 작지 않은 값 중 가장 왼쪽에 있는 값의 위치
            ll left = s.empty() ? 0 : s.top() + 1;
            ll width = get_sum(left, i - 1);
            ans = std::max(ans, height * width);
        }
        s.push(i);
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    preprocess();
    std::cout << solve() << '\n';
}