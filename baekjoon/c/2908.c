#include <stdio.h>
#include <tchar.h>

#define MAX(x,y) x>y? x:y

void main() {
	char num[2][4];
	int i, j, rvs[2] = { 0 };
	for (i = 0; i <= 1; i++) {
		scanf("%s", num[i]);
		getchar();
		for (j = 0; j <= 2; j++) {
			rvs[i] = rvs[i] * 10 + (num[i][2 - j] - '0');
		}
	}
	printf("%d", MAX(rvs[0], rvs[1]));
	/*TCHAR a[10] = _T("°¡³ª´Ù");
	_tprintf(_T("%s"),a);*/
}
