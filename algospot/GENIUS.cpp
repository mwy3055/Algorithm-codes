#include <bits/stdc++.h>

int n, k, m, len[50], q[50];
double t[50][50];
const int MOD = 5;

void getinput()
{
    std::cin >> n >> k >> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> len[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> t[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> q[i];
    }
}

class SquareMatrix
{
private:
    int siz;
    std::vector<std::vector<double>> matrix;

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
        matrix = std::vector<std::vector<double>>(siz, std::vector<double>(siz, 0));
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
                auto &r = this->matrix[i][k];
                for (int j = 0; j < siz; j++)
                    rtn[i][j] += r * b.matrix[k][j];
            }
        }

        return rtn;
    }
    std::vector<double> &operator[](int i)
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

void solve()
{
    SquareMatrix w(4 * n);
    for (int i = 0; i < 3 * n; i++)
        w[i][i + n] = 1;
    for (int i = 0; i < n; i++)
    {
        // c[t+1][i] = sum of c[t+1-len[j]][j]*t[j][i]
        for (int j = 0; j < n; j++)
        {
            w[3 * n + i][(4 - len[j]) * n + j] = t[j][i];
        }
    }
    SquareMatrix wk = SquareMatrix::pow(w, k);

    for (int i = 0; i < m; i++)
    {
        auto &cur = q[i];
        double ans = 0;
        for (int t = 0; t < len[cur]; t++)
        {
            ans += wk[(3 - t) * n + cur][3 * n];
        }
        std::cout << std::fixed << ans << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.precision(9);

    int c;
    std::cin >> c;
    while (c--)
    {
        getinput();
        solve();
    }
}