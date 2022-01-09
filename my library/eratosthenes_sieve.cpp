using ll = long long;

const ll MAX = 100000;
bool isprime[MAX + 1];
int smallest_pf[MAX + 1]; // i의 가장 작은 소인수
int count_pf[MAX + 1];    // i의 서로 다른 소인수의 개수

void calculate()
{
    std::memset(isprime, true, MAX + 1);
    isprime[0] = isprime[1] = false;
    for (ll i = 2; i <= MAX; i++)
    {
        if (isprime[i])
        {
            for (ll p = i * i; p <= MAX; p += i)
            {
                isprime[p] = false;
                if (!smallest_pf[p])
                    smallest_pf[p] = i;
                count_pf[p]++;
            }
        }
    }
}