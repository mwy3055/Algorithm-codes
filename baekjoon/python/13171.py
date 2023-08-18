a, x, MOD = int(input()), int(input()), 1000000007
muls = [a % MOD for _ in range(64)]
i, sq = 1, 2
while sq <= x:
    muls[i] = (muls[i-1]*muls[i-1]) % MOD
    sq *= 2
    i += 1
tobin = reversed(format(x, 'b'))
ans = 1
for i, c in enumerate(tobin):
    if c == '1':
        ans = (ans*muls[i]) % MOD
print(ans)
