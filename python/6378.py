from sys import stdin, stdout
for line in stdin:
    num=int(line)
    if num==0:
        break
    while num>=10:
        d=0
        while num>0:
            d+=num%10
            num=num//10
        num=d
    stdout.write(str(num)+'\n')