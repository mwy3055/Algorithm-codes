#include <bits/stdc++.h>

using pii = std::pair<int, int>;
using ll = long long;

int n, r, c, sr, sc;
std::string s;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void getinput()
{
    std::cin >> n >> r >> c >> sr >> sc >> s;
}

int get_dir(char c)
{
    if (c == 'E')
        return 0;
    else if (c == 'W')
        return 1;
    else if (c == 'S')
        return 2;
    else if (c == 'N')
        return 3;
    else
        exit(-1);
}

ll hash(int cr, int cc)
{
    return (ll)cr * c + cc;
}

pii solve()
{
    std::unordered_set<ll> v;

    int cr = sr, cc = sc;
    v.insert(hash(cr, cc));
    for (auto &inst : s)
    {
        int dir = get_dir(inst);
        do
        {
            cr += dr[dir];
            cc += dc[dir];
        } while (v.find(hash(cr, cc)) != v.end());
        v.insert(hash(cr, cc));
    }
    return pii(cr, cc);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++)
    {
        getinput();
        auto [ar, ac] = solve();
        std::cout << "Case #" << i << ": " << ar << ' ' << ac << '\n';
    }
}