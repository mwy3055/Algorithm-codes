#include <bits/stdc++.h>

struct box
{
    int lx, ly, lz, px, py, under_z;
    box(int lx, int ly, int lz, int px, int py) : lx(lx), ly(ly), lz(lz), px(px), py(py), under_z(0) {}
};

int Lx, Ly, n;
std::vector<box> boxes;

void getinput()
{
    std::cin >> Lx >> Ly >> n;
    for (int i = 0; i < n; i++)
    {
        int lx, ly, lz, px, py;
        std::cin >> lx >> ly >> lz >> px >> py;
        boxes.emplace_back(lx, ly, lz, px, py);
    }
}

bool overlaps(box b1, box b2)
{
    return b1.px < b2.px + b2.lx &&
           b1.px + b1.lx > b2.px &&
           b1.py < b2.py + b2.ly &&
           b1.py + b1.ly > b2.py;
}

int solve()
{
    std::vector<box> piled;
    piled.push_back(box(Lx, Ly, 0, 0, 0));

    for (auto &box : boxes)
    {
        auto max_bottom = 0;
        for (auto &piled_box : piled)
        {
            if (overlaps(piled_box, box))
            {
                max_bottom = std::max(max_bottom, piled_box.under_z + piled_box.lz);
            }
        }
        box.under_z = max_bottom;
        piled.push_back(box);
    }

    int ans = 0;
    for (auto &box : piled)
        ans = std::max(ans, box.under_z + box.lz);
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}