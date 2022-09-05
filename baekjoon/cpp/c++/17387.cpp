#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> pii;

int ccw(pii x, pii y, pii z) // (x, y)
{
    // 벡터 XY와 벡터 YZ를 외적하자.
    ll v1x = y.first - x.first, v1y = y.second - x.second;
    ll v2x = z.first - y.first, v2y = z.second - y.second;
    // 외적 벡터의 Z축 성분
    // 양수: 반시계, 음수: 시계, 0: 한 직선 위에 존재
    ll cross = v1x * v2y - v1y * v2x;
    if (cross > 0)
        return 1;
    else if (cross < 0)
        return -1;
    else
        return 0;
}
bool meet_segment(pii a, pii b, pii c, pii d) // (x1, y1) ~ (x2, y2), (x3, y3) ~ (x4, y4)
{
    // 선분 AB를 기준으로 C와 D가 반대인가?
    int ab = ccw(a, b, c) * ccw(a, b, d);
    // 선분 CD를 기준으로 A와 B가 반대인가?
    int cd = ccw(c, d, a) * ccw(c, d, b);
    // 한 직선 위에 있다면
    if (ab == 0 && cd == 0)
    {
        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);
        return c <= b && a <= d;
    }
    // 둘 다 반대여야 교차
    // 등호 빼면 안 된다!
    return ab <= 0 && cd <= 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    pii a, b, c, d;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
    cout << meet_segment(a, b, c, d);
}