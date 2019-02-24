#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int sum_(int month,int date);
void rst(int a);

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	int k = sum_(x, y);
	rst(k);
	return 0;
}

int sum_(int month, int date) {
	int sum = 0;
	for (int i = 1; i <= month-1; i++) {
		if (i == 2)
			sum += 28;
		else if (i == 4||i==6||i==9||i==11)
			sum += 30;
		else
			sum += 31;
	}
	return sum+date-1;
}
void rst(int a) {
	switch (a%7) {
	case 1:
		printf("TUE");
		break;
	case 2:
		printf("WED");
		break;
	case 3:
		printf("THU");
		break;
	case 4:
		printf("FRI");
		break;
	case 5:
		printf("SAT");
		break;
	case 6:
		printf("SUN");
		break;
	default:
		printf("MON");
	}
}