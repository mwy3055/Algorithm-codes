from sys import stdin

def score(s):
    if s == 'A+':
        return 4.3
    elif s == 'A0':
        return 4.0
    elif s == 'A-':
        return 3.7
    elif s == 'B+':
        return 3.3
    elif s == 'B0':
        return 3.0
    elif s == 'B-':
        return 2.7
    elif s == 'C+':
        return 2.3
    elif s == 'C0':
        return 2.0
    elif s == 'C-':
        return 1.7
    elif s == 'D+':
        return 1.3
    elif s == 'D0':
        return 1.0
    elif s == 'D-':
        return 0.7
    else:
        return 0.0


ssum, gpa = 0, 0
stdin.readline()
for line in stdin:
    subj, hak, sco = line.strip().split()
    tscore = score(sco)*100
    ssum += int(hak)
    gpa += tscore*int(hak)
print('{0:0.2f}'.format(round(gpa/ssum)/100))
