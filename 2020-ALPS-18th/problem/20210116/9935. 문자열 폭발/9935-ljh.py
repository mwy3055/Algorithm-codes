#https://dojang.io/mod/page/view.php?id=2299 참고
# https://www.acmicpc.net/board/view/62259#comment-105324 질문 답변

s = input()
bomb = input()

tmp=''
for i in range(len(bomb)):
    tmp = tmp+' ';

table = str.maketrans(bomb, tmp)
change = s.translate(table)
result = change.replace(" ","")

if(result == ""):
    print("FRULA")
else:
    print(result)

