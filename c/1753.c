#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct line {
	int v, cost;
} line;

#define swap(a,b) {line temp=PQ[a];PQ[a]=PQ[b];PQ[b]=temp;}
#define INF (1 << 30)

line PQ[300001];    //우선순위 큐. 1번부터 저장
int idx;            //큐의 맨 끝 인덱스(실질사이즈)

line** adj;         //인접리스트: 간선의 비용과 목적지 저장. 1번부터 저장
int* listidx;       //인접리스트의 인덱스. 1번부터 저장
int* maxidx;        //인접리스트의 맨 끝 인덱스. 리스트 확장에 쓰임 -> vector 구현

int* dist;          //1번 점으로부터 나머지 점으로의 최단 거리. (인덱스)=(수)
char* visit;        //방문했는지 여부 체크. 1이면 방문

void LinePush(int, int, int);
void Push(int, int);
void Pop();
void dijk(int);

int main()
{
	int v, e, k; //노드 수, 간선 수, 출발점
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

	for (i = 0; i < e; i++) //간선 입력받는 부분
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		LinePush(from, to, cost);
	}

	Push(0, k);
	while (idx) //큐가 빌 때까지
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

void Push(int cost, int v) //거리, 정점
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

		if (PQ[i].cost < PQ[i * 2].cost && PQ[i].cost < PQ[i * 2 + 1].cost) //최소힙 만족
			return;
		else
		{
			int minidx = PQ[i * 2].cost < PQ[i * 2 + 1].cost ? i * 2 : i * 2 + 1;
			swap(i, minidx);
			i = minidx;
		}
	}
}