#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int k, len = 0;
	int i = 1, j, l;
	scanf("%d", &k);

	while ((1<<i) - 2 < k) //2의 n제곱은 1<<n
	{
		i++;
		len++;
	}
	l = len - 1; //인덱스
	char* str = (char*)calloc(len + 1, sizeof(char));
	int nth = k - (1<<len) +1;

	//nth를 이진수로
	while (nth)
	{
		str[l--] = nth % 2;
		nth /= 2;
	}

	for (j = 0; j < len; j++)
		printf("%d", str[j] ? 7 : 4);

	free(str);
}
//k를 이진수로 바꾸면 된다. 다만 이렇게 하면 출력할 길이를 따로 알아야겠지.
