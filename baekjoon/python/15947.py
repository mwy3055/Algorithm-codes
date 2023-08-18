word = {1: "baby", 2: "sukhwan", 5: "very", 6: "cute",
        9: "in", 10: "bed", 13: "baby", 14: "sukhwan"}
n = int(input())
nth, r = n//14+1, (n-1) % 14+1
if r in word:
    print(word[r])
else:
    s = 'turu'+'ru'*nth if r % 2 == 1 else 'tu'+'ru'*nth
    cnt = s.count('ru')
    if 5 <= cnt:
        print('tu+ru*%d' % cnt)
    else:
        print(s)
