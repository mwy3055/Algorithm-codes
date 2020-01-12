#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x1[4], y1[4], x2[4], y2[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    set<pii> s;
    for (int i = 0; i < 4; i++)
    {
        for (int x = x1[i]; x < x2[i]; x++)
        {
            for (int y = y1[i]; y < y2[i]; y++)
            {
                pii temp = pii(x, y);
                if (s.find(temp) == s.end())
                    s.insert(temp);
            }
        }
    }
    cout << s.size();
}