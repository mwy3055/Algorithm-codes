#include <bits/stdc++.h>
using namespace std;

vector<double> differentiate(const vector<double> &poly)
{
    vector<double> rtn;
    int siz = poly.size();
    for (int i = 1; i < siz; i++)
        rtn.push_back(poly[i] * i);

    return rtn;
}
vector<double> solveNaive(const vector<double> &poly)
{
    vector<double> solve;
    int siz = poly.size();
    if (siz == 2)
    {
        double ans = (-1) * poly[0] / poly[1];
        solve.push_back(ans);
    }
    else if (siz == 3)
    {
        auto &a = poly[2], &b = poly[1], &c = poly[0];
        double D = b * b - 4 * a * c;
        if (D > 0)
        {
            solve.push_back((-b + sqrt(D)) / (2 * a));
            solve.push_back((-b - sqrt(D)) / (2 * a));
        }
    }

    sort(solve.begin(), solve.end());
    return solve;
}
double evaluate(const vector<double> &poly, double x)
{
    double ans = 0, sq = 1;
    int siz = poly.size();
    for (int i = 0; i < siz; i++)
    {
        ans += sq * poly[i];
        sq *= x;
    }

    return ans;
}

const double L = 10;
vector<double> solve(const vector<double> &poly)
{
    int n = poly.size() - 1;
    if (n <= 2)
        return solveNaive(poly);

    vector<double> derivative = differentiate(poly);
    vector<double> sols = solve(derivative);

    sols.insert(sols.begin(), -L - 1);
    sols.insert(sols.end(), L + 1);

    vector<double> ans;
    int siz = sols.size();
    for (int i = 1; i < siz; i++)
    {
        double x1 = sols[i - 1], x2 = sols[i];
        double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);

        if (y1 * y2 > 0)
            continue;

        if (y1 > y2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }

        for (int i = 0; i < 150; i++)
        {
            double midx = (x1 + x2) / 2;
            double midy = evaluate(poly, midx);

            if (y1 * midy > 0)
            {
                y1 = midy;
                x1 = midx;
            }
            else
            {
                y2 = midy;
                x2 = midx;
            }
        }

        ans.push_back((x1 + x2) / 2);
    }

    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(8);

    int c;
    cin >> c;
    while (c--)
    {
        int n;
        cin >> n;
        vector<double> poly(n + 1);
        for (int i = n; i >= 0; i--)
            cin >> poly[i];

        vector<double> ans = solve(poly);
        for (auto &c : ans)
            cout << c << ' ';
        cout << '\n';
    }
}