#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class weapon
{
public:
    ll attack;
    ll force;
    ll cc;
    ll cd;
    ll as;
    weapon(ll a = 0, ll f = 0, ll cc = 0, ll cd = 0, ll as = 0)
        : attack(a), force(f), cc(cc), cd(cd), as(as) {}

    weapon operator-(const weapon w)
    {
        weapon rtn(
            this->attack - w.attack,
            this->force - w.force,
            this->cc - w.cc,
            this->cd - w.cd,
            this->as - w.as);

        return rtn;
    }
    weapon operator+(const weapon w)
    {
        weapon rtn(
            this->attack + w.attack,
            this->force + w.force,
            this->cc + w.cc,
            this->cd + w.cd,
            this->as + w.as);

        return rtn;
    }

    ll power()
    {
        ll rtn = attack * (100 + force) * (100 * (100 - min(cc, (ll)100)) + min(cc, (ll)100) * cd) * (100 + as);
        return rtn;
    }
};

istream &operator>>(istream &in, weapon &w)
{
    in >> w.attack >> w.force >> w.cc >> w.cd >> w.as;
    return in;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    weapon kr, pb, w_kr, w_pb;
    cin >> kr >> pb >> w_kr >> w_pb;

    ll pow_kr = kr.power(), pow_kr2 = (kr - w_kr + w_pb).power();
    if (pow_kr < pow_kr2)
        cout << '+' << '\n';
    else if (pow_kr > pow_kr2)
        cout << '-' << '\n';
    else
        cout << 0 << '\n';

    ll pow_pb = pb.power(), pow_pb2 = (pb - w_pb + w_kr).power();
    if (pow_pb < pow_pb2)
        cout << '+' << '\n';
    else if (pow_pb > pow_pb2)
        cout << '-' << '\n';
    else
        cout << 0 << '\n';
}