#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n; //문제의 입력 변수
ll s, e;
ll ans; // 문제의 해답에 해당하는 변수 선언 
vector<pair<ll, ll>> v;

//10억 정도의 범위일때는 무한대로 이 숫자를 채용 
const int INF =  0x3f3f3f3f;


void initialize()
{
    ans = 0; //답의 초기화 
    s = -INF;
    e = -INF;
}

//문제의 입력을 받는 함수 
void input()
{
    cin >> n;

    ll s, e;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        
        v.emplace_back(s, e);
    }
}

//solution에 필요한 함수 구현하는 공간

// 위에서 구현한 함수들을 통해 문제를 직접적으로 풀어내는 함수
// 문제의 요구사항이 간단할 경우 함수를 모듈화하지 않고 solution 내부에서 함수를 구현해도 됨 
void solution()
{
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++)
    {
        auto cur = v[i];
        ll ns = cur.first;
        ll ne = cur.second;

        //다음 선분이 이전 선분의 길이에 포함될 때

        if(s <= ns && ne <= e) continue;

        //우선은 새로운 선분을 더함 
        ans += ne - ns;

        //겹치는 구간 존재할때 
        if (ns < e) {
            ans -= (e - ns);
        }

        s = ns;
        e = ne;
        

    }
    
}

void solve()
{
    initialize();
    input(); //입력을 받고
    solution(); // 푼다

    cout << ans << '\n'; //답을 출력
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
