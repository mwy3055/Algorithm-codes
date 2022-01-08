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
		asc[i] = *(pstr + i)-97; //아스키코드 'a'는 97, 배열의 처음은 0번째이므로 수를 맞춰주기 위해 97을 뺌
	} 
	for(i=0; i<100;i++) {
		if (apb[asc[i]] == (-1))  //(아스키코드 값-97)번째 배열의 값이 -1이라면, 즉 아직 그 문자가 나오지 않은 상황일 때에만
			apb[asc[i]] = i;      //자릿수 대입
		if (asc[i] = 0)
			break;
	}
	for (i = 0; i < 26; i++)
		printf("%d ", apb[i]);
}

//포인터 배열을 선언한 후에도 str를 다른 문자열로 바꿀 수 있다.
//printf("%d  ", asc[i]); i번째 문자의 아스키코드 출력. %c로 바꾸면 문자가 출력된다.