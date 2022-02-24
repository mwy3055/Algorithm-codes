#include <iostream>
using namespace std;

int map[100][100];
int solve(int n, int l)
{
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int idx = 0, curlen = 1;
        bool avail = true;
        while (avail && idx < n - 1)
        {
            if (map[i][idx] == map[i][idx + 1])
            {
                idx++;
                curlen++;
            }
            else if (map[i][idx] + 1 == map[i][idx + 1])
            {
                // 2 3 3 3
                if (curlen < l)
                    avail = false;
                else
                {
                    idx++;
                    curlen = 1;
                }
            }
            else if (map[i][idx] == map[i][idx + 1] + 1)
            {
                // 3 2 2 2
                int low = map[i][idx + 1], lidx = idx + 1, llen = 1;
                while (lidx < n - 1 && map[i][lidx + 1] == low && llen < l)
                {
                    lidx++, llen++;
                }
                if ((lidx < n && map[i][lidx] < map[i][lidx + 1]) || llen < l)
                    avail = false;
                else
                {
                    idx = lidx;
                    curlen = 0;
                }
            }
            else
                avail = false;
        }
        if (avail)
            ans++;
    }

    for (int j = 0; j < n; j++)
    {
        int idx = 0, curlen = 1;
        bool avail = true;
        while (avail && idx < n - 1)
        {
            if (map[idx][j] == map[idx + 1][j])
            {
                idx++;
                curlen++;
            }
            else if (map[idx][j] + 1 == map[idx + 1][j])
            {
                // 2 3 3 3
                if (curlen < l)
                    avail = false;
                else
                {
                    idx++;
                    curlen = 1;
                }
            }
            else if (map[idx][j] == map[idx + 1][j] + 1)
            {
                // 3 2 2 2
                int low = map[idx + 1][j], lidx = idx + 1, llen = 1;
                while (lidx < n - 1 && map[lidx + 1][j] == low && llen < l)
                {
                    lidx++, llen++;
                }
                if ((lidx < n && map[lidx][j] < map[lidx + 1][j]) || llen < l)
                    avail = false;
                else
                {
                    idx = lidx;
                    curlen = 0;
                }
            }
            else
                avail = false;
        }
        if (avail)
            ans++;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    cout << solve(n, l);
}