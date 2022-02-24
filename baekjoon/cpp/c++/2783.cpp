#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, y;
    double ratio[101], minv;
    cin >> ratio[0] >> y;
    ratio[0] /= y;
    minv = ratio[0];

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ratio[i] >> y;
        ratio[i] /= y;
        if (ratio[i] < minv)
            minv = ratio[i];
    }
    cout << minv * 1000;
}