#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
class SquareMatrix
{
private:
    int siz;
    vector<vector<int>> matrix;

public:
    static SquareMatrix identity(int n)
    {
        SquareMatrix rtn(n);
        for (int i = 0; i < n; i++)
            rtn.matrix[i][i] = 1;
        return rtn;
    }

    int getsiz() const
    {
        return this->siz;
    }

    SquareMatrix(int siz = 0) : siz(siz)
    {
        matrix = vector<vector<int>>(siz, vector<int>(siz, 0));
    }
    SquareMatrix operator*(SquareMatrix b)
    {
        if (this->siz != b.siz)
            return SquareMatrix(1);

        SquareMatrix rtn(siz);
        for (int k = 0; k < siz; k++)
        {
            for (int i = 0; i < siz; i++)
            {
                long long r = this->matrix[i][k];
                for (int j = 0; j < siz; j++)
                    rtn[i][j] = (rtn[i][j] + r * b.matrix[k][j]) % MOD;
            }
        }

        return rtn;
    }
    vector<int> &operator[](int i)
    {
        return matrix[i];
    }

    static SquareMatrix pow(const SquareMatrix &a, int m)
    {
        if (m == 1)
            return a;

        SquareMatrix result = SquareMatrix::pow(a, m / 2);
        result = result * result;
        if (m % 2)
            result = result * a;
        return result;
    }
};

// 정보과학관	전산관	신양관	진리관	학생회관	형남공학관	한경직	미래관

int data[][8] = {0, 1, 0, 0, 0, 0, 0, 1,
                 1, 0, 1, 0, 0, 0, 0, 1,
                 0, 1, 0, 1, 0, 0, 1, 1,
                 0, 0, 1, 0, 1, 0, 1, 0,
                 0, 0, 0, 1, 0, 1, 0, 0,
                 0, 0, 0, 0, 1, 0, 1, 0,
                 0, 0, 1, 1, 0, 1, 0, 1,
                 1, 1, 1, 0, 0, 0, 1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    SquareMatrix m(8);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            m[i][j] = data[i][j];

    int d;
    cin >> d;
    SquareMatrix result = SquareMatrix::pow(m, d);
    cout << result[0][0];
}