#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h>

void main() {
	int i, asc[101], apb[26];
	for (i = 0; i < 26; i++)
		apb[i] = (-1);
	char str[101] = { '\0' };
	char *pstr = &str; //?
	scanf("%s", str);
	for (i = 0; i < 100; i++) {
		asc[i] = *(pstr + i)-97; //�ƽ�Ű�ڵ� 'a'�� 97, �迭�� ó���� 0��°�̹Ƿ� ���� �����ֱ� ���� 97�� ��
	} 
	for(i=0; i<100;i++) {
		if (apb[asc[i]] == (-1))  //(�ƽ�Ű�ڵ� ��-97)��° �迭�� ���� -1�̶��, �� ���� �� ���ڰ� ������ ���� ��Ȳ�� ������
			apb[asc[i]] = i;      //�ڸ��� ����
		if (asc[i] = 0)
			break;
	}
	for (i = 0; i < 26; i++)
		printf("%d ", apb[i]);
}

//������ �迭�� ������ �Ŀ��� str�� �ٸ� ���ڿ��� �ٲ� �� �ִ�.
//printf("%d  ", asc[i]); i��° ������ �ƽ�Ű�ڵ� ���. %c�� �ٲٸ� ���ڰ� ��µȴ�.