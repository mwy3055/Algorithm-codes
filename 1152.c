#include <stdio.h>
#include <string.h>

void main(){
	char str[1000000];
	int i = 0, num = 0; //num�� ������ ����
	gets_s(str,sizeof(str));
	while(str[i]){
		if(str[i]==32)
			num++;
		i++;
	}
	if (str[0] == 32) num--; 
	if (str[strlen(str)-1] == 32) num--; //����ü..�̷� ���̽��� �׽�Ʈ�ϴ� ������?
	printf("%d", num + 1);
}