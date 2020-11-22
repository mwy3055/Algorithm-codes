
#include <bits/stdc++.h>

using namespace std;

int n;
char x, y;
string tmp; //버리는 문자열 
int graph[55][55];

void floydWarshall(void)
{
	for (int k = 0; k <= 51; k++)
		for (int i = 0; i <= 51; i++)
			for (int j = 0; j <= 51; j++)
				//1->1 이런거 어차피 0이라 
				if (i == j)
					continue;
				else if (graph[i][k] && graph[k][j])
					//경로가 존재한다면 true 아니면 false
				{
					if (graph[i][j] == 0)
						//한번엔 못가도 경유노드를 거쳐 탐색이 가능할때
						graph[i][j] = graph[i][k] + graph[k][j];
					
					else
						//핵심! 더 빠른 경로로 갱신 
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
					
				}
}

int ctoi(char c) { return c>='A' && c<='Z'?c-'A':c-'a'+26; }
char itoc(int n) { return n<26?'A'+n:'a'+n-26; }

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x >> tmp >> y;     
        graph[ctoi(x)][ctoi(y)] = 1;
    }

    floydWarshall();

    int cnt = 0;

    for(int i = 0; i <= 51; i++){
        for(int j = 0; j <= 51; j++){
            if(graph[i][j] != 0) 
                cnt++;
        }
    }
    cout << cnt << '\n';

     for(int i = 0; i <= 51; i++){
        for(int j = 0; j <= 51; j++){
            if(graph[i][j] != 0)
                cout << itoc(i) << " => " << itoc(j) << '\n';
        }
    }


    return 0;
}
