#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//void rxSort(int*, int, int, int);
//사실 정렬 따위 필요 없는 것이었다

int main()
{
	int n, i;
	scanf("%d", &n);
	int* temp = (int*)malloc(10000 * sizeof(int)); //같은 수가 최대 1000만 회 나올 수 있으므로 int형으로 선언

	for (i = 0; i<10000; i++)
		*(temp + i) = 0;

	for (i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		temp[t - 1]++;
	}

	for (i = 0; i < 10000; i++)
	{
		if (*(temp+i))
		{
			for (int j = 0; j < temp[i]; j++)
				printf("%d\n", i + 1);
		}
	}

	free(temp);
}

/*
* @data  정수 배열
* @size  data의 정수들의 개수
* @p  숫자의 최대 자리수
* @k  기수(10진법을 사용한다면 10


void rxSort(int *data, int size, int p, int k) {
	int *counts, // 특정 자릿수에서 숫자들의 카운트
		*temp; // 정렬된 배열을 담을 임시 장소
	int index, pval, i, j, n;
	counts = (int*)malloc(k * sizeof(int));
	temp = (int*)malloc(size * sizeof(int));
	for (n = 0; n<p; n++) 
	{ // 1의 자리, 10의자리, 100의 자리 순으로 진행
		for (i = 0; i<k; i++)
			counts[i] = 0; // 초기화
						   // 위치값 계산.
						   // n:0 => 1,  1 => 10, 2 => 100
		pval = (int)pow((double)k, (double)n);
		// 각 숫자의 발생횟수를 센다.
		for (j = 0; j<size; j++) 
		{
			// 253이라는 숫자라면
			// n:0 => 3,  1 => 5, 2 => 2
			index = (int)(data[j] / pval) % k;
			counts[index] = counts[index] + 1;
		}
		// 카운트 누적합을 구한다. 계수정렬을 위해서.
		for (i = 1; i<k; i++)
			counts[i] = counts[i] + counts[i - 1];
		// 카운트를 사용해 각 항목의 위치를 결정한다.
		// 계수정렬 방식
		for (j = size - 1; j >= 0; j--) // 뒤에서부터 시작
		{ 
			index = (int)(data[j] / pval) % k;
			temp[counts[index] - 1] = data[j];
			counts[index] = counts[index] - 1; // 해당 숫자 카운트를 1 감소
		}
		// 임시 데이터 복사
		memcpy(data, temp, size * sizeof(int));
	}

	free(counts);
	free(temp);
}
*/