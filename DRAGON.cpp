#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll length[51];
void init()
{
    length[0] = 1;
    for (int i = 1; i <= 50; i++)
        length[i] = 2 * length[i - 1] + 2;
}
char solve(const string &curve, int gen, int skip)
{
    if (gen == 0)
        return curve[skip];
    for (auto &c : curve)
    {
        if (c == 'X' || c == 'Y')
        {
            if (length[gen] <= skip)
                skip -= length[gen];
            else if (c == 'X')
                return solve("X+YF", gen - 1, skip);
            else
                return solve("FX-Y", gen - 1, skip);
        }
        else if (0 < skip)
            skip--;
        else
            return c;
    }
    return 'Q'; // never executed
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    int c;
    cin >> c;
    while (c--)
    {
        int n, p, l;
        cin >> n >> p >> l;
        for (int i = 0; i < l; i++)
            cout << solve("FX", n, p - 1 + i);
        cout << '\n';
    }
}