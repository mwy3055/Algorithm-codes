#include <iostream>
using namespace std;

bool added[100][100];
void check(int &x, int &y, int &area)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (!added[x + i][y + j])
            {
                added[x + i][y + j] = true;
                area++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, area = 0;
    cin >> n;
    for (int a = 0; a < n; a++)
    {
        int x, y;
        cin >> x >> y;
        check(x, y, area);
    }
    cout << area;
}