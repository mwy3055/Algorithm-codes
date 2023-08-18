#include <bits/stdc++.h>
using namespace std;

struct bug
{
    bool oddbirth; //홀수년에 태어났다면 true, 아니라면 false
    int splitcount;
    bug(bool birth) : oddbirth(birth), splitcount(0) {}
    bool isdead()
    {
        if (oddbirth)
            return splitcount == 3;
        else
            return splitcount == 4;
    }
    bug split(int year)
    {
        splitcount++;
        return bug(year % 2);
    }
};

int solve(int n)
{
    deque<bug> l;
    l.push_back(bug(1));

    for (int year = 2; year <= n; year++)
    {
        int siz = l.size();
        while (siz--)
        {
            auto b = l.front();
            l.pop_front();
            l.push_back(b.split(year));
            if (!b.isdead())
                l.push_back(b);
        }
    }

    return l.size();
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", solve(n));
}