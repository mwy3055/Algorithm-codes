#include <bits/stdc++.h>
using namespace std;

class square
{
public:
    int x1, y1, x2, y2;
    square(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    static bool isout(square i, square j)
    {
        //두 사각형이 만난다면 true, 만나지 않으면 false를 리턴
        if (i.x1 > j.x1)
        {
            auto temp = i;
            i = j;
            j = temp;
        }

        //아예 바깥
        if (i.x2 < j.x1 || i.y1 > j.y2 || i.y2 < j.y1)
            return true;
        //j가 i 안에 있음
        if (i.x1 < j.x1 && i.x2 > j.x2 && i.y1 < j.y1 && i.y2 > j.y2)
            return true;
        return false;
    }
};
istream &operator>>(istream &in, square &s)
{
    in >> s.x1 >> s.y1 >> s.x2 >> s.y2;
    return in;
}

square sq[1001];
int parent[1001];

int getparent(int i)
{
    if (i == parent[i])
        return i;
    return parent[i] = getparent(parent[i]);
}
void merge(int u, int v)
{
    int pu = getparent(u), pv = getparent(v);
    if (pu < pv)
    {
        swap(pu, pv);
    }
    parent[pu] = pv;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> sq[i];
        parent[i] = i;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (!(square::isout(sq[i], sq[j])))
                merge(i, j);
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
        if (parent[i] == i)
            ans++;

    cout << ans - 1; //(union의 수)-1
}