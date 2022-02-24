#include <stdio.h>

int main() {
	char n[8];
	int i = -1, count[9] = { 0 }, set;
	gets(n);
	while (n[++i]) {
		if (n[i] == '6' || n[i] == '9') count[6]++;
		else count[n[i] - '0']++;
	}
	count[6] = (int)((double)count[6] / 2 + 0.5);
	set = count[0];
	for (i = 1; i <= 8; i++)
		if (set < count[i]) set = count[i];
	printf("%d", set);
}

//6,9의 합이 i개일 때 필요한 세트의 수: (int)((double)i/2+0.5) ->i를 2로 나눈 수의 반올림