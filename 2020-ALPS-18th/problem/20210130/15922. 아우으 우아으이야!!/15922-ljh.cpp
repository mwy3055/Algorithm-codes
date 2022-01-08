#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n; //������ �Է� ����
ll s, e;
ll ans; // ������ �ش信 �ش��ϴ� ���� ���� 
vector<pair<ll, ll>> v;

//10�� ������ �����϶��� ���Ѵ�� �� ���ڸ� ä�� 
const int INF =  0x3f3f3f3f;


void initialize()
{
    ans = 0; //���� �ʱ�ȭ 
    s = -INF;
    e = -INF;
}

//������ �Է��� �޴� �Լ� 
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

//solution�� �ʿ��� �Լ� �����ϴ� ����

// ������ ������ �Լ����� ���� ������ ���������� Ǯ��� �Լ�
// ������ �䱸������ ������ ��� �Լ��� ���ȭ���� �ʰ� solution ���ο��� �Լ��� �����ص� �� 
void solution()
{
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++)
    {
        auto cur = v[i];
        ll ns = cur.first;
        ll ne = cur.second;

        //���� ������ ���� ������ ���̿� ���Ե� ��

        if(s <= ns && ne <= e) continue;

        //�켱�� ���ο� ������ ���� 
        ans += ne - ns;

        //��ġ�� ���� �����Ҷ� 
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
    input(); //�Է��� �ް�
    solution(); // Ǭ��

    cout << ans << '\n'; //���� ���
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
