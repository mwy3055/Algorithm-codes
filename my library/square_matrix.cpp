#include <iostream>
#include <vector>
using namespace std;

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
                int r = this->matrix[i][k];
                for (int j = 0; j < siz; j++)
                    rtn[i][j] += r * b.matrix[k][j];
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
        if (m == 0)
            return SquareMatrix::identity(a.siz);

        if (m % 2)
            return SquareMatrix::pow(a, m - 1) * a;

        SquareMatrix half = SquareMatrix::pow(a, m / 2);
        return half * half;
    }
};

istream &operator>>(istream &in, SquareMatrix &matrix)
{
    int siz = matrix.getsiz();
    for (int i = 0; i < siz; i++)
    {
        for (int j = 0; j < siz; j++)
        {
            cin >> matrix[i][j];
        }
    }

    return in;
}

ostream &operator<<(ostream &out, const SquareMatrix &matrix)
{
    int siz = matrix.getsiz();
    for (int i = 0; i < siz; i++)
    {
        for (int j = 0; j < siz; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}