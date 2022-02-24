#include <bits/stdc++.h>

using ll = long long;

struct room
{
    ll t, a, h;
    room(ll t = 0, ll a = 0, ll h = 0) : t(t), a(a), h(h) {}
};

#define DEBUG

ll n, atk;
std::vector<room> rooms;

void getinput()
{
    std::cin >> n >> atk;
    for (int i = 0; i < n; i++)
    {
        int a, h, t;
        std::cin >> a >> h >> t;
        rooms.emplace_back(a, h, t);
    }
}

ll damage(ll attack, room &r)
{
    auto turn = (r.h - 1) / attack + 1;
    return (turn - 1) * r.a;
}

bool check(ll hp)
{
    const ll max_hp = hp;
    ll attack = atk;
    for (auto &r : rooms)
    {
        if (r.t == 1)
        {
            auto dmg = damage(attack, r);
            hp -= dmg;
            if (hp <= 0)
                return false;
        }
        else
        {
            attack += r.a;
            hp = std::min(max_hp, hp + r.h);
        }
    }
    return true;
}

ll solve()
{
    if (n == 1)
    {
        return damage(atk, rooms[0]) + 1;
    }

    ll left = 1, right = 1LL << 62;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        if (check(mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}
