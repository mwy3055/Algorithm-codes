#include <bits/stdc++.h>

using ll = long long;
const ll MOD = 1000000007;

class SquareMatrix
{
private:
    int siz;
    std::vector<std::vector<int>> matrix;

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
        matrix = std::vector<std::vector<int>>(siz, std::vector<int>(siz, 0));
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
                auto r = this->matrix[i][k] % MOD;
                for (int j = 0; j < siz; j++)
                {
                    rtn[i][j] = (rtn[i][j] + ((r * b.matrix[k][j]) % MOD)) % MOD;
                }
            }
        }
        return rtn;
    }
    std::vector<int> &operator[](int i)
    {
        return matrix[i];
    }

    static SquareMatrix pow(const SquareMatrix &a, int m)
    {
        if (m == 0)
            return SquareMatrix::identity(a.siz);
        if (m == 1)
            return a;

        SquareMatrix result = SquareMatrix::pow(a, m / 2);
        result = result * result;
        if (m % 2)
            result = result * a;
        return result;
    }
};

std::ostream &operator<<(std::ostream &out, SquareMatrix &matrix)
{
    int siz = matrix.getsiz();
    for (int i = 0; i < siz; i++)
    {
        for (int j = 0; j < siz; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return std::cout;
}

int t, n, d;
std::vector<SquareMatrix> maps;

void getinput()
{
    std::cin >> t >> n >> d;
    for (int i = 0; i < t; i++)
    {
        SquareMatrix map(n);
        int m;
        std::cin >> m;
        for (int j = 0; j < m; j++)
        {
            int a, b, c;
            std::cin >> a >> b >> c;
            map[a - 1][b - 1] = c;
        }
        maps.push_back(map);
    }
}

void solve()
{
    // 행렬을 (D/T)번 제곱한 후, 나머지를 곱하자.
    SquareMatrix all = SquareMatrix::identity(n);
    for (auto &map : maps)
        all = all * map;

    SquareMatrix ans = SquareMatrix::pow(all, d / t);
    auto remainder = d % t;
    for (int i = 0; i < remainder; i++)
    {
        ans = ans * maps[i];
    }
    std::cout << ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}