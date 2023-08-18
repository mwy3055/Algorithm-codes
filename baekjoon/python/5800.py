from sys import stdout
k=int(input())
for i in range(k):
    line=list(map(int,input().split()))
    n=line[0]
    line=sorted(line[1:])
    md=0
    for j in range(n-1):
        if md<line[j+1]-line[j]:
            md=line[j+1]-line[j]
    stdout.write('Class '+str(i+1)+'\n')
    stdout.write('Max '+str(line[n-1])+', Min '+str(line[0])+', Largest gap '+str(md)+'\n')