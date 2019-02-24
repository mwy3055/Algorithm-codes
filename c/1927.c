#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int nd[100001]; //인덱스=수, 빈 노드의 값은 0

void delete(int);
void mainf();
#define swap(a,b) {int temp=nd[a];nd[a]=nd[b];nd[b]=temp;}

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		mainf();
	}
}
void mainf()
{
	int t, idx = 0;
	scanf("%d", &t);
	if (t)
	{
		nd[++idx] = t;
		int i = idx;
		while (i > 1)
		{
			if (nd[i]< nd[i / 2] && nd[i])
				swap(i, i / 2);
			i /= 2;
		}
	}
	else
	{
		printf("%d\n", nd[1]);
		nd[1] = nd[idx];
		nd[idx] = 0;
		if (idx)
			idx--;
		delete(idx);
	}
}

void delete(int idx) //idx:맨 끝 노드 번호
{
	int i = 1;
	while (1)
	{
		if (2 * i > idx) //i번째 노드가 자식을 갖지 않을 때
			return;
		if (nd[i * 2] && nd[i * 2 + 1]) //둘 다 값이 있을 때
		{
			if ((nd[i] < nd[i * 2]) && (nd[i] < nd[i * 2 + 1])) //부모가 제일 작을 때
				return;
			int minidx = nd[i * 2] < nd[i * 2 + 1] ? i * 2 : i * 2 + 1;
			swap(i, minidx);
			i = minidx;
		}
		else if (nd[i * 2] && (nd[i] > nd[i * 2])) //왼쪽 자식만 있을 때
		{
			swap(i, i * 2);
			i *= 2;
		}
		else //둘 다 0
			return;
	}
}
/*
힙의 삽입 연산

1) 힙에 새로운 요소가 들어오면, 일단 새로운 노드를 힙의 마지막 노드에 이어서 삽입
2) 삽입 후에 새로운 노드를 부모노드들과 교환해서 힙의 성질을 만족
*/

/*
힙의 삭제 연산

  1) 힙의 루트에서 최고 깊이, 최 우측에 있던 노드를 루트 노드로 옮겨온다.
  -> 힙의 완전이진트리를 유지하는 반면에 힙의 순서 속성이 파괴된다.
  -> 이를 복원하기 위한 작업을 다음 단계에서부터 시작한다.
  2) 옮겨온 노드의 양쪽 자식을 비교하여 작은 쪽 자식과 위치 교환을 한다.
  (힙 순서 속성이 지켜지려면 부모 노드는 양쪽 자식보다 작은 값을 가져야 하기 때문)
  3) 옮겨온 노드가 더 이상 자식이 없는 잎노드가 되거나 양쪽 자식보다 작은 값을 갖는 경우에는 삭제 연산을 종료한다.
  그렇지 않은 경우에는 단계2를 반복한다.

*/
