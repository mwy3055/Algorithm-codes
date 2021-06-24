#include <bits/stdc++.h>

using ll = long long;
const int MOD = 1000000007;

class SquareMatrix
{
private:
    int siz;
    std::vector<std::vector<ll>> matrix;

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
        matrix = std::vector<std::vector<ll>>(siz, std::vector<ll>(siz, 0));
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
                {
                    rtn[i][j] += ((r % MOD) * (b.matrix[k][j] % MOD)) % MOD;
                    rtn[i][j] %= MOD;
                }
            }
        }

        return rtn;
    }
    std::vector<ll> &operator[](int i)
    {
        return matrix[i];
    }

    static SquareMatrix pow(const SquareMatrix &a, ll m)
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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll n;
    std::cin >> n;
    if (n <= 1)
    {
        std::cout << n << '\n';
        exit(0);
    }
    SquareMatrix w(2);
    w[0][0] = 0;
    w[0][1] = 1;
    w[1][0] = 1;
    w[1][1] = 1;
    auto squared = SquareMatrix::pow(w, n - 1);
    std::cout << squared[1][1] << '\n';
}