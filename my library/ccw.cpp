int ccw(pair<int, int> x, pair<int, int> y, pair<int, int> z) // (x, y)
{
    int v1x = y.first - x.first, v1y = y.second - x.second;
    int v2x = z.first - y.first, v2y = z.second - y.second;
    int cross = v1x * v2y - v1y * v2x; // overflow!!
    if (cross > 0)
        return 1;
    else if (cross < 0)
        return -1;
    else
        return 0;
}

// ccw > 0: counterclockwise
// ccw < 0: clockwise
// ccw = 0: parallel