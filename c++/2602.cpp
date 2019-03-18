#include <iostream>
#include <string>
using namespace std;

int dpa[100][20], dpd[100][20];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string duru, angel, devil;
    cin >> duru >> devil >> angel;

    int dulen = duru.length(), brlen = devil.length();

    dpa[0][0] = (angel[0] == duru[0]);
    dpd[0][0] = (devil[0] == duru[0]);
    for (int i = 1; i < brlen; i++)
    {
        dpa[i][0] = (angel[i] == duru[0]);
        dpd[i][0] = (devil[i] == duru[0]);
        for (int k = 1; k < dulen; k++)
        {
            if (angel[i] == duru[k])
                dpa[i][k] += dpd[i - 1][k - 1];
            if (devil[i] == duru[k])
                dpd[i][k] += dpa[i - 1][k - 1];
            int a = 1;
        }
    }

    cout << dpa[brlen - 1][dulen - 1] + dpd[brlen - 1][dulen - 1];
}