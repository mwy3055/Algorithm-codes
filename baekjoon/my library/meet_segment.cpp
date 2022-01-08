bool meet_segment(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) // (x1, y1) ~ (x2, y2), (x3, y3) ~ (x4, y4)
{
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0)
    {
        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}