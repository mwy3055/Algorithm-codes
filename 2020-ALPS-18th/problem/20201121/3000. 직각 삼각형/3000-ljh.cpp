
#include <bits/stdc++.h>

using namespace std;

int n, x, y, cnt;

const int MAX = 100000;

long long xpoint[MAX+1];
long long ypoint[MAX+1];
pair <int, int> point[MAX+1]; //연산자 우선순위? 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> point[i].first >> point[i].second;
        xpoint[point[i].first]++;
        ypoint[point[i].second]++;

    }

    long long sum = 0;

    for(int i = 0; i < n; i++)
    {
        // int xcnt = 0;
        // int ycnt = 0;

        // for (int i = 0; i < vx.size(); i++)
        // {
        //     if (nx == vx[i])
        //         xcnt++;
        //     if (ny == vy[i])
        //         ycnt++;
        // }

        // xcnt--;
        // ycnt--;


        // if(xpoint[nx] == 0 || ypoint[ny] == 0)
        //     continue;
        // else
            sum += (xpoint[point[i].first]-1)*(ypoint[point[i].second]-1);
    }

    cout << sum << '\n';

    return 0;
}
