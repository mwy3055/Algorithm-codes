typedef long long ll;
const ll MOD = 1000000007, MAX = 4000000;
ll fac[MAX + 1], inv[MAX + 1];

ll power(ll a, ll x) // a^x
{
    ll ret = 1;
    while (x)
    {
        if (x % 2)
            ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        x /= 2;
    }
    return ret;
}
void preprocess()
{
    fac[0] = 1;
    for (int i = 1; i <= MAX; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
    inv[MAX] = power(fac[MAX], MOD - 2);
    for (int i = MAX - 1; i >= 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
}
ll combination(int n, int k)
{
    if (n == k || k == 0)
        return 1;
    ll rtn = (fac[n] * inv[n - k]) % MOD;
    rtn = (rtn * inv[k]) % MOD;
    return rtn;
}
