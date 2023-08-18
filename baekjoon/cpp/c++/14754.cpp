#include <iostream>
using namespace std;
int num[1000][1000];
bool ismax[1000][1000] = {false};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    long sum = 0, msum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int midx = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> num[i][j];
            sum += num[i][j];
            if (num[i][midx] < num[i][j])
                midx = j;
        }
        ismax[i][midx] = true;
        msum += num[i][midx];
    }

    for (int i = 0; i < m; i++)
    {
        int midx = 0;
        for (int j = 1; j < n; j++)
        {
            if (num[midx][i] < num[j][i])
                midx = j;
        }
        if (!ismax[midx][i])
            msum += num[midx][i];
    }
    cout << sum - msum;
}