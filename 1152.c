#include <stdio.h>
#include <string.h>

void main(){
	char str[1000000];
	int i = 0, num = 0; //num은 띄어쓰기의 개수
	gets_s(str,sizeof(str));
	while(str[i]){
		if(str[i]==32)
			num++;
		i++;
	}
	if (str[0] == 32) num--; 
	if (str[strlen(str)-1] == 32) num--; //도대체..이런 케이스를 테스트하는 이유가?
	printf("%d", num + 1);
}