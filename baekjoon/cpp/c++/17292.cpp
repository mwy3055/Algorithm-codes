#include <bits/stdc++.h>
using namespace std;

struct card
{
    int num;
    char c;
    card(int num = 0, char c = '\0') : num(num), c(c) {}
    char gethex()
    {
        if (num < 10)
            return '0' + num;
        else
            return 'a' + (num - 10);
    }
};
struct Pair
{
    card a, b;
    Pair(card a = card(), card b = card()) : a(a), b(b) {}
    card &getbignumcard()
    {
        return a.num < b.num ? b : a;
    }
    int getsmallnum()
    {
        return a.num < b.num ? a.num : b.num;
    }
    int getbignum()
    {
        return a.num < b.num ? b.num : a.num;
    }
    bool succnum()
    {
        int diff = abs(a.num - b.num);
        return diff == 1 || diff == 14;
    }
    bool samenum()
    {
        return a.num == b.num;
    }
    bool samecolor()
    {
        return a.c == b.c;
    }
    int getrank()
    {
        if (succnum())
            return 1;
        else if (samenum())
            return 2;
        else
            return 3;
    }
};

struct compare
{
    bool operator()(Pair &a, Pair &b) const
    {
        int pa = a.getrank(), pb = b.getrank();
        if (pa != pb)
            return pa < pb;

        //서열 같을 때
        //1. 색이 같은 쌍
        if (a.samecolor() && !b.samecolor())
            return true;
        else if (!a.samecolor() && b.samecolor())
            return false;

        //2. 큰 수가 큰 쪽
        int ba = a.getbignum(), bb = b.getbignum();
        if (ba != bb)
            return ba > bb;

        //3. 작은 수가 큰 쪽
        int sa = a.getsmallnum(), sb = b.getsmallnum();
        if (sa != sb)
            return sa > sb;

        //4.큰 수가 검은색
        card &bca = a.getbignumcard(), bcb = b.getbignumcard();
        if (bca.c == 'b' && bcb.c != 'b')
            return true;
        else if (bca.c != 'b' && bcb.c == 'b')
            return false;

        return true;
    }
};

ostream &operator<<(ostream &out, Pair &p)
{
    out << p.a.gethex() << p.a.c << p.b.gethex() << p.b.c;
    return out;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    card cards[6];
    for (int i = 0; i < 6; i++)
    {
        char num, c, temp;
        cin >> num >> c;
        if (i < 5)
            cin >> temp;

        if (isdigit(num))
            num -= '0';
        else
            num = num - 'a' + 10;
        cards[i] = card(num, c);
    }

    Pair pairs[15];
    int idx = 0;
    for (int i = 0; i < 6; i++)
        for (int j = i + 1; j < 6; j++)
            pairs[idx++] = Pair(cards[i], cards[j]);

    sort(pairs, pairs + 15, compare());

    for (int i = 0; i < 15; i++)
        cout << pairs[i] << '\n';
}