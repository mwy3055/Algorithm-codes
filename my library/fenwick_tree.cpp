using ll = long long;

const int SIZE = (1 << 20) + 1;
ll BIT[SIZE];
ll getsum(ll i) // get sum of interval [1, i]
{
    ll sum = 0;
    while (i > 0)
    {
        sum += BIT[i];
        i -= i & -i;
    }
    return sum;
}

void add(ll i, ll val) // increase num[i] by val
{
    while (i < SIZE)
    {
        BIT[i] += val;
        i += i & -i;
    }
}