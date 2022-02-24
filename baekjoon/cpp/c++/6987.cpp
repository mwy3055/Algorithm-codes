#include <bits/stdc++.h>

struct result
{
    int win, draw, lose;
    result(int w = 0, int d = 0, int l = 0) : win(w), draw(d), lose(l) {}
    int sum()
    {
        return win + draw + lose;
    }
    bool operator==(const result r)
    {
        return this->win == r.win && this->draw == r.draw && this->lose == r.lose;
    }
    bool operator!=(const result r)
    {
        return !((*this) == r);
    }
};
using vr = std::vector<result>;

int idx[][2] = {0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 1, 2, 1, 3, 1, 4, 1, 5, 2, 3, 2, 4, 2, 5, 3, 4, 3, 5, 4, 5};
bool ans;
void solve(vr &results, vr &test, int dep)
{
    if (ans)
        return;
    if (dep == 15)
    {
        bool tans = true;
        for (int i = 0; i < 6; i++)
        {
            if (results[i] != test[i])
            {
                tans = false;
                break;
            }
        }
        ans |= tans;
        return;
    }

    int a = idx[dep][0], b = idx[dep][1];

    test[a].win++, test[b].lose++;
    solve(results, test, dep + 1);
    test[a].win--, test[b].lose--;

    test[a].lose++, test[b].win++;
    solve(results, test, dep + 1);
    test[a].lose--, test[b].win--;

    test[a].draw++, test[b].draw++;
    solve(results, test, dep + 1);
    test[a].draw--, test[b].draw--;
}

bool available(vr &results)
{
    int win = 0, draw = 0, lose = 0;
    for (auto &r : results)
    {
        win += r.win;
        draw += r.draw;
        lose += r.lose;
    }
    draw /= 2;
    return win == 15 - draw && lose == 15 - draw;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    for (int i = 0; i < 4; i++)
    {
        ans = false;
        vr results, test(6);
        for (int j = 0; j < 6; j++)
        {
            int w, d, l;
            std::cin >> w >> d >> l;
            results.emplace_back(w, d, l);
        }
        if (available(results))
            solve(results, test, 0);
        std::cout << (ans ? 1 : 0) << ' ';
    }
}