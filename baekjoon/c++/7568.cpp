#include <bits/stdc++.h>
using namespace std;

class Volume
{
public:
    int w, h, rank;
    bool operator>(const Volume a)
    {
        return (this->w > a.w) && (this->h > a.h);
    }
};
Volume v[50];

void getinput(int &n)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].w >> v[i].h;
    }
}
void setVolumerank(int n)
{
    for (int i = 0; i < n; i++)
    {
        int rank = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j] > v[i])
                rank++;
        }
        v[i].rank = rank + 1;
    }
}
int main()
{
    int n;
    getinput(n);
    setVolumerank(n);

    for (int i = 0; i < n; i++)
        cout << v[i].rank << ' ';
}