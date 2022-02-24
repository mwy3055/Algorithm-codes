#include <bits/stdc++.h>

int n, height[50][50], npost;
std::vector<int> heights;
char map[50][50];
bool visit[50][50];

struct coord
{
    int r, c;
    coord(int r = 0, int c = 0) : r(r), c(c) {}
    coord operator+(coord crd)
    {
        return coord(r + crd.r, c + crd.c);
    }
    bool isin()
    {
        return 0 <= r && r < n &&
               0 <= c && c < n;
    }
};

coord start;
coord delta[] = {coord(-1, 0), coord(-1, 1), coord(0, 1), coord(1, 1), coord(1, 0), coord(1, -1), coord(0, -1), coord(-1, -1)};

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> map[i][j];
            if (map[i][j] == 'P')
            {
                start = coord(i, j);
            }
            else if (map[i][j] == 'K')
            {
                npost++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> height[i][j];
            heights.push_back(height[i][j]);
        }
    }
}

void preprocess()
{
    std::sort(heights.begin(), heights.end());
    heights.erase(std::unique(heights.begin(), heights.end()), heights.end());
}

bool satisfy_limit(coord &c, int &min, int &max)
{
    int h = height[c.r][c.c];
    return min <= h && h <= max;
}

// [min_height, max_height] 구간의 높이인 칸만 이동하여 모두 배달 가능?
bool possible(int &min_height, int &max_height)
{
    if (!satisfy_limit(start, min_height, max_height))
    {
        return false;
    }
    std::queue<coord> q;
    std::memset(visit, 0, sizeof(visit));

    q.push(start);
    visit[start.r][start.c] = true;
    int left = npost;
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        if (map[top.r][top.c] == 'K')
        {
            left--;
        }

        for (int i = 0; i < 8; i++)
        {
            auto next = top + delta[i];
            if (next.isin() && !visit[next.r][next.c] && satisfy_limit(next, min_height, max_height))
            {
                q.push(next);
                visit[next.r][next.c] = true;
            }
        }
    }
    return left == 0;
}

int solve()
{
    int ans = 1e6;
    for (int i = 0; i < heights.size(); i++)
    {
        // parametric search of index
        // [left, right]
        int left = i, right = heights.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (possible(heights[i], heights[mid]))
            {
                right = mid - 1;
                ans = std::min(ans, heights[mid] - heights[i]);
            }
            else
            {
                left = mid + 1;
            }
        }
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