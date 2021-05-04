const int n = 100000;
bool isprime[n + 1];
int smallest_pf[n + 1]; // i의 가장 작은 소인수
int count_pf[n + 1];    // i의 서로 다른 소인수의 개수

void init()
{
    std::memset(isprime, true, n + 1);
}

void calculate()
{
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (isprime[i])
        {
            for (int p = i * i; p <= n; p += i)
            {
                isprime[p] = false;
                if (!smallest_pf[p])
                    smallest_pf[p] = i;
                count_pf[p]++;
            }
        }
    }
}