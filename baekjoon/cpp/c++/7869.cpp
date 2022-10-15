#include <bits/stdc++.h>

struct circle
{
    double x, y, r;
    circle(double x, double y, double r) : x(x), y(y), r(r) {}
};

std::pair<circle, circle> getinput()
{
    double x1, y1, r1, x2, y2, r2;
    std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    return std::make_pair(circle(x1, y1, r1), circle(x2, y2, r2));
}

double dist(circle c1, circle c2)
{
    auto dx = c1.x - c2.x, dy = c1.y - c2.y;
    return dx * dx + dy * dy;
}

int pos_case(circle &c1, circle &c2)
{
    auto d = dist(c1, c2);

    auto rsum = c1.r + c2.r, rdiff = c1.r - c2.r;
    auto sum_sq = rsum * rsum, diff_sq = rdiff * rdiff;

    if (sum_sq < d)
        return 1;
    else if (sum_sq == d)
        return 2;
    else if (diff_sq < d && d < sum_sq)
        return 3;
    else if (d == diff_sq)
        return 4;
    else if (d < diff_sq)
        return 5;
    else
        exit(-1);
}

double sq(double d)
{
    return d * d;
}

// 코사인법칙. r1과 d가 만드는 각의 코사인값을 구한다.
double cosine(double r1, double r2, double d)
{
    double cosine = (sq(r1) + d - sq(r2)) / (2 * r1 * std::sqrt(d));
    return cosine;
}

auto PI = std::atan(1) * 4;

// 부분 겹침
double calculate(circle &c1, circle &c2)
{
    auto d = dist(c1, c2);

    auto cosine1 = cosine(c1.r, c2.r, d), cosine2 = cosine(c2.r, c1.r, d);
    auto theta1 = std::acos(cosine1), theta2 = std::acos(cosine2);
    auto sine1 = std::sin(2 * theta1), sine2 = std::sin(2 * theta2);

    auto area1 = (sq(c1.r) * theta1) - (sq(c1.r) * sine1 / 2);
    auto area2 = (sq(c2.r) * theta2) - (sq(c2.r) * sine2 / 2);
    return area1 + area2;
}

double solve(circle &c1, circle &c2)
{
    // c1이 더 큰 원
    if (c1.r < c2.r)
        std::swap(c1, c2);

    int type = pos_case(c1, c2);
    if (type == 1 || type == 2)
        return 0;
    else if (type == 3)
        return calculate(c1, c2);
    else if (type == 4 || type == 5)
        return c2.r * c2.r * PI;
    else
        return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.precision(3);

    auto [c1, c2] = getinput();
    std::cout << std::fixed << solve(c1, c2) << '\n';
}