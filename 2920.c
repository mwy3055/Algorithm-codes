#include <stdio.h>

void check_asc(short* sc);
void check_dsc(short* sc);

void main() {
	short scale[8];
	int i = 0;
	for (; i <= 7; i++) scanf("%hd", scale + i);
	switch (*scale) {
	case 1:
		check_asc(scale);
		break;
	case 8:
		check_dsc(scale);
		break;
	}
}

void check_asc(short* sc) {
	int i = 0, count = 1;
	for (; i <= 7; i++) {
		if (*(sc + i) != i+1) {
			count = 0;
			break;
		}
	}
	if (count == 1) printf("ascending");
	else printf("mixed");
}
void check_dsc(short* sc) {
	int i = 0, count = 1;
	for (; i <= 7; i++) {
		if (*(sc + i) != 8 - i) {
			count = 0;
			break;
		}
	}
	if (count == 1) printf("descending");
	else printf("mixed");
}