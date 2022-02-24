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
    for (int i = 1; i < brlen; i++) //���ٸ��� i�� ���� ���� ����
    {
        dpa[i][0] = (angel[i] == duru[0]);
        dpd[i][0] = (devil[i] == duru[0]);
        for (int k = 1; k < dulen; k++) //���ٸ��� i�� ���ڿ� �η縶���� k�� ���ڸ� ��
        {
            if (angel[i] == duru[k])
                for (int j = 0; j < i; j++)
                    dpa[i][k] += dpd[j][k - 1];
            if (devil[i] == duru[k])
                for (int j = 0; j < i; j++)
                    dpd[i][k] += dpa[j][k - 1];
        }
    }

    int sum = 0;
    for (int i = 0; i < brlen; i++)
    {
        sum += dpa[i][dulen - 1] + dpd[i][dulen - 1];
    }
    cout << sum;
}