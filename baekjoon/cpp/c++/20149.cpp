#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair<int, int>;
using pdd = std::pair<double, double>;

const int MEET = 0, MEET_ON_LINE = 1, NO_MEET = 2;

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
int meet_segment(pii a, pii b, pii c, pii d) // (x1, y1) ~ (x2, y2), (x3, y3) ~ (x4, y4)
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
        if (b == c || a == d || ((a != c) ^ (b != d)))
            return MEET;
        return (c <= b && a <= d ? MEET_ON_LINE : NO_MEET);
    }
    // 둘 다 반대여야 교차
    // 등호 빼면 안 된다!
    return (ab <= 0 && cd <= 0 ? MEET : NO_MEET);
}

pdd make_line(pii p1, pii p2)
{
    double dx = p2.first - p1.first, dy = p2.second - p1.second;
    double d = dy / dx;
    return pdd(d, p1.second - d * p1.first);
}

double meet_x(pdd line1, pdd line2)
{
    return (line2.second - line1.second) / (line1.first - line2.first);
}

double get_y(pdd line, double x)
{
    return line.first * x + line.second;
}

pdd meet_point(pii a, pii b, pii c, pii d)
{
    if (a > b)
        std::swap(a, b);
    if (c > d)
        std::swap(c, d);

    // 두 선분이 한 점에서 만나는 경우
    if (b == c)
        return pdd(b.first, b.second);
    else if (a == d)
        return pdd(a.first, a.second);

    // 기울기가 무한인 경우
    if (a.first == b.first && c.first == d.first)
    {
        return pdd(0, 0);
    }
    if (a.first == b.first)
    {
        auto line = make_line(c, d);
        auto y = get_y(line, a.first);
        return pdd(a.first, y);
    }
    if (c.first == d.first)
    {
        auto line = make_line(a, b);
        auto y = get_y(line, c.first);
        return pdd(c.first, y);
    }

    // 일반적인 경우
    // 직선의 방정식의 교점을 구한다.
    auto l1 = make_line(a, b), l2 = make_line(c, d);
    auto x = meet_x(l1, l2);
    auto y = get_y(l1, x);
    return std::make_pair(x, y);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    pii a, b, c, d;
    std::cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
    int meets = meet_segment(a, b, c, d);
    std::cout << (meets != NO_MEET) << '\n';
    if (meets == MEET)
    {
        auto point = meet_point(a, b, c, d);
        if (!std::isnan(point.first))
        {
            std::cout.precision(12);
            std::cout << point.first << ' ' << point.second;
        }
    }
}