


#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

const int MAX = 52;
int n;
char x, y;
string tmp; //버리는 문자열 

int graph[MAX+1][MAX+1];


int ctoi(char c) { return c>='A' && c<='Z'?c-'A':c-'a'+26; }
char itoc(int n) { return n<26?'A'+n:'a'+n-26; }

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(graph, INF, sizeof(graph));

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x >> tmp >> y;     
        graph[ctoi(x)][ctoi(y)] = 1;
    }

    // Floyd-warshall
    for (int k = 0; k < 52; k++)
    {
        for (int i = 0; i < 52; i++)
        {
            for (int j = 0; j < 52; j++)
            {
                if (i != j && j != k && k != i)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int cnt = 0;

    for(int i = 0; i < 52; i++){
        for(int j = 0; j < 52; j++){
            if(i != j  && graph[i][j] != INF) 
                cnt++;
        }
    }
    cout << cnt << '\n';

     for(int i = 0; i < 52; i++){
        for(int j = 0; j < 52; j++){
            if(i != j && graph[i][j] != INF)
                cout << itoc(i) << " => " << itoc(j) << '\n';
        }
    }


    return 0;
}
