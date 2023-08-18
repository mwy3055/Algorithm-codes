#include <bits/stdc++.h>

using ll = long long;

ll a, b;
const ll MOD = 1e9;

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
                auto r = this->matrix[i][k];
                for (int j = 0; j < siz; j++)
                    rtn[i][j] = (rtn[i][j] + (r * b.matrix[k][j]) % MOD) % MOD;
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

// return fibo[n] % MOD
ll f(ll n)
{
    if (n <= 2)
        return 1;
    else if (n == 3)
        return 2;

    auto matrix = SquareMatrix(2);
    matrix[0][0] = matrix[0][1] = matrix[1][0] = 1;
    auto pow = SquareMatrix::pow(matrix, n - 2);
    return ((pow[0][0] % MOD) + (pow[0][1] % MOD)) % MOD;
}

int solve()
{
    return (f(b + 2) - f(a + 1) + MOD) % MOD;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> a >> b;
    std::cout << solve() << '\n';
}