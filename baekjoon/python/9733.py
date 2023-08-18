from sys import stdin
tasks = ['Re', 'Pt', 'Cc', 'Ea', 'Tb', 'Cm', 'Ex']
count = [0 for i in range(7)]
total = 0
for line in stdin:
    for task in line.split():
        if task in tasks:
            idx = tasks.index(task)
            count[idx] += 1
        total += 1
for i in range(7):
    print((tasks[i]+' '+str(count[i])+' %.2f') % (count[i]/total))
print('Total '+str(total)+' 1.00')
