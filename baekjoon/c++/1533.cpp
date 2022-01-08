#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000003;

class SquareMatrix
{
public:
    int siz;
    vector<vector<int>> m;

    SquareMatrix(int siz = 0) : siz(siz)
    {
        m = vector<vector<int>>(siz, vector<int>(siz));
    }
    SquareMatrix operator*(const SquareMatrix &b)
    {
        SquareMatrix rtn(siz);
        for (int k = 0; k < siz; k++)
        {
            for (int i = 0; i < siz; i++)
            {
                long long r = m[i][k];
                for (int j = 0; j < siz; j++)
                    rtn.m[i][j] = (rtn.m[i][j] + r * b.m[k][j]) % MOD;
            }
        }
        return rtn;
    }
};

SquareMatrix pow(SquareMatrix a, int m)
{
    if (m == 1)
        return a;

    SquareMatrix result = pow(a, m / 2);
    result = result * result;
    if (m % 2)
        result = result * a;
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s, e, t;
    cin >> n >> s >> e >> t;
    s--, e--;

    SquareMatrix matrix(n * 5);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            matrix.m[i * 5 + j][i * 5 + j - 1] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            int c = s[j] - '0';
            if (c > 0)
                matrix.m[i * 5][j * 5 + c - 1] = 1;
        }
    }
    matrix = pow(matrix, t);
    cout << matrix.m[s * 5][e * 5];
}