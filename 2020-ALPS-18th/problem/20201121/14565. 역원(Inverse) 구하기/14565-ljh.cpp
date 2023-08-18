#include <bits/stdc++.h>

using namespace std;

long long Extended_Euclid(long long r1, long long r2)
{
    long long r, q, s, s1 = 1, s2 = 0, t, t1 = 0, t2 = 1, tmp = r1;

    while (r2)
    {
        q = r1 / r2;
        r = r1 % r2;
        s = s1 - q * s2;
        t = t1 - q * t2;

        // printf("%4d %4d %4d %4d %4d %4d %4d %4d %4d %4d\n", q, r1, r2, r, s1, s2, s, t1, t2, t);

        r1 = r2;
        r2 = r;
        s1 = s2;
        s2 = s;
        t1 = t2;
        t2 = t;
    }
    // printf("%4d %4d %4d      %4d %4d      %4d          \n\n", q, r1, r2, s1, s2, t1);


    // printf("s : %lld , t : %lld \n", s1, t1);

    if (r1 == 1) //역원이 있음
    {
        if (t1 < 0)
            t1 += tmp;
        return t1;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long num1, num2, invers = 0;

    cin >> num1 >> num2;

    // printf("   q   r1   r2    r   s1   s2    s   t1   t2    t\n");

    if (num1 > num2)
        invers = Extended_Euclid(num1, num2);
    else
        invers = Extended_Euclid(num2, num1);

    if (invers)
        cout << num1 - num2 << ' ' << invers << '\n';
    else
        cout << num1 - num2 << ' ' << -1 << '\n';
}
