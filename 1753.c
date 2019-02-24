#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct line {
	int v, cost;
} line;

#define swap(a,b) {line temp=PQ[a];PQ[a]=PQ[b];PQ[b]=temp;}
#define INF (1 << 30)

line PQ[300001];    //�켱���� ť. 1������ ����
int idx;            //ť�� �� �� �ε���(����������)

line** adj;         //��������Ʈ: ������ ���� ������ ����. 1������ ����
int* listidx;       //��������Ʈ�� �ε���. 1������ ����
int* maxidx;        //��������Ʈ�� �� �� �ε���. ����Ʈ Ȯ�忡 ���� -> vector ����

int* dist;          //1�� �����κ��� ������ �������� �ִ� �Ÿ�. (�ε���)=(��)
char* visit;        //�湮�ߴ��� ���� üũ. 1�̸� �湮

void LinePush(int, int, int);
void Push(int, int);
void Pop();
void dijk(int);

int main()
{
	int v, e, k; //��� ��, ���� ��, �����
	int i;
	scanf("%d %d %d", &v, &e, &k);

	adj = (line**)calloc(v + 1, sizeof(line*));
	listidx = (int*)calloc(v + 1, sizeof(int));
	maxidx = (int*)calloc(v + 1, sizeof(int));
	dist = (int*)calloc(v + 1, sizeof(int));
	visit = (char*)calloc(v + 1, sizeof(char));
	visit[0] = 1;
	for (i = 1; i <= v; i++)
	{
		maxidx[i] = 1;
		*(adj + i) = (line*)calloc(1, sizeof(line));
		dist[i] = i == k ? 0 : INF;
	}

	for (i = 0; i < e; i++) //���� �Է¹޴� �κ�
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		LinePush(from, to, cost);
	}

	Push(0, k);
	while (idx) //ť�� �� ������
	{
		int u;
		do
		{
			u = PQ[1].v;
			Pop();
		} while (idx && visit[u]);

		visit[u] = 1;
		dijk(u);
	}

	for (i = 1; i <= v; i++)
	{
		if (dist[i] != INF)
			printf("%d\n", dist[i]);
		else
			printf("INF\n");
	}

	for (i = 0; i <= v; i++)
		free(*(adj + i));
	free(listidx);
	free(maxidx);
	free(dist);
	free(visit);
}

void LinePush(int from, int to, int cost)
{
	if (listidx[from] + 1 == maxidx[from])
	{
		maxidx[from] *= 2;
		*(adj + from) = (line*)realloc(*(adj + from), maxidx[from] * sizeof(line));
	}
	//*(adj+from)=(line*)realloc(*(adj+from),++listidx[from]*sizeof(line));
	adj[from][++listidx[from]].v = to;
	adj[from][listidx[from]].cost = cost;
}

void dijk(int u)
{
	for (int i = 1; i <= listidx[u]; i++)
	{
		int* curr = &dist[adj[u][i].v], renew = dist[u] + adj[u][i].cost;
		if (renew < *curr)
		{
			*curr = renew;
			Push(*curr, adj[u][i].v);
		}
	}
}

void Push(int cost, int v) //�Ÿ�, ����
{
	PQ[++idx].cost = cost;
	PQ[idx].v = v;
	int i = idx;
	while (i > 1)
	{
		if (PQ[i].cost < PQ[i / 2].cost)
			swap(i, i / 2)
			i /= 2;
	}
}

void Pop()
{
	PQ[1] = PQ[idx];
	PQ[idx--].cost = INF;

	int i = 1;
	while (1)
	{
		if (i * 2 > idx)
			return;

		if (PQ[i].cost < PQ[i * 2].cost && PQ[i].cost < PQ[i * 2 + 1].cost) //�ּ��� ����
			return;
		else
		{
			int minidx = PQ[i * 2].cost < PQ[i * 2 + 1].cost ? i * 2 : i * 2 + 1;
			swap(i, minidx);
			i = minidx;
		}
	}
}