#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long arr[101] = { 0,1,1,1 };
		int n;
		scanf("%d", &n);
		for (int i = 4; i <= n; i++)
			arr[i] = arr[i - 2] + arr[i - 3];
		printf("%lld\n", arr[n]);
	}
}