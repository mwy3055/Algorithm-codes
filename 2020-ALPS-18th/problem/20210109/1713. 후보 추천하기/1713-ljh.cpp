//학생의 추천수
//학생의 사진이 게시된 시각
// 2 1 4
// 3 1 4
// 3 5 4
// 3 5 6
// 2 5 6
// 2 7 6
//섬세하게 구현

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
int n, rec_cnt;
int recommend[MAX + 1]; //추천 수 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    //사진 틀에 사진을 넣은 시간, 해당 사진의 학생 번호
    vector<pair<int, int>> v(n, {0, 0});

    cin >> rec_cnt;

    for (int i = 0; i < rec_cnt; i++)
    {
        int snum;
        cin >> snum;
        recommend[snum]++;

        bool replace = true;

        for (int j = 0; j < n; j++)
        {
            //액자가 비어있을 때
            if (v[j].second == 0)
            {
                v[j].second = snum;
                v[j].first = i;
                replace = false;
                break;
            }

            //이미 액자에 있는 경우
            else if (v[j].second == snum)
            {
                replace = false;
                break;
            }
        }

        //사진 갱신
        if (replace)
        {
            int idx = 0;
            for (int j = 1; j < n; j++)
            {
                //추천개수 낮은 거 여러개인 경우
                if (recommend[v[j].second] == recommend[v[idx].second])
                {
                    //시간이 가장 오래된 순
                    if (v[j].first < v[idx].first)
                    {
                        idx = j;
                    }
                }
                //추천 개수 낮은 순
                else if (recommend[v[j].second] < recommend[v[idx].second])
                {
                    idx = j;
                }
            }
            //초기화
            recommend[v[idx].second] = 0;
            v[idx].first = i;
            v[idx].second = snum;
        }
    }

    vector<int> picture;
    for (int i = 0; i < n; i++)
    {
        picture.push_back(v[i].second);
    }

    sort(picture.begin(), picture.end());
    for (int i = 0; i < n; i++)
    {
        cout << picture[i] << ' ';
    }

    return 0;
}
