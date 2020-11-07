#include <iostream>
using namespace std;

struct Fish
{
    int y, x;
};

Fish fish[100];

inline int max(int a, int b)
{
    return a < b ? b : a;
}
inline bool ismapin(int &y, int &x, int &n)
{
    return 0 <= y && y < n && 0 <= x && x < n;
}

int solve(int &n, int &l, int &m, int &f)
{
    int ans = 0;
    for (int width = 1; width < l / 2; width++)
    {
        int height = l / 2 - width;
        for (int ty = -height; ty <= 0; ty++)
        {
            for (int tx = -width; tx <= 0; tx++)
            {
                int ymin = fish[f].y + ty, xmin = fish[f].x + tx;
                int ymax = ymin + height, xmax = xmin + width, tans = 0;
                if (!ismapin(ymin, xmin, n) || !ismapin(ymax, xmax, n))
                    continue;
                for (int i = 0; i < m; i++)
                {
                    if (ymin <= fish[i].y && fish[i].y <= ymax && xmin <= fish[i].x && fish[i].x <= xmax)
                        tans++;
                }
                ans = max(ans, tans);
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, l, m;
    cin >> n >> l >> m;
    for (int i = 0; i < m; i++)
    {
        int y, x;
        cin >> y >> x;
        fish[i] = {y - 1, x - 1};
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, solve(n, l, m, i));
    }
    cout << ans;
}