#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &fence, int s, int e) //[s, e] 구간에서의 최댓값 구하기
{
    /*
        [s, e] 구간을 반으로 나눈다. 이때 답의 경우는 세 가지이다.
        1. 가장 큰 직사각형이 왼쪽 구간에 있을 때
        2. 가장 큰 직사각형이 오른쪽 구간에 있을 때
        3. 가장 큰 직사각형이 왼쪽과 오른쪽 구간에 걸쳐 있을 때
    */

    if (s == e)
        return fence[s];

    int mid = (s + e) / 2;
    // 1, 2
    int lans = solve(fence, s, mid), rans = solve(fence, mid + 1, e);

    // 3 시작
    int l = mid, r = mid + 1;
    int height = min(fence[l], fence[r]);
    int mans = height * 2;
    while (s < l && r < e)
    {
        if (fence[l - 1] < fence[r + 1])
        {
            r++;
            height = min(height, fence[r]);
        }
        else
        {
            l--;
            height = min(height, fence[l]);
        }
        mans = max(mans, height * (r - l + 1));
    }

    if (s == l)
    {
        while (r < e)
        {
            r++;
            height = min(height, fence[r]);
            mans = max(mans, height * (r - l + 1));
        }
    }
    else if (r == e)
    {
        while (s < l)
        {
            l--;
            height = min(height, fence[l]);
            mans = max(mans, height * (r - l + 1));
        }
    }
    // 3 끝

    return max(mans, max(lans, rans));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    while (c--)
    {
        int n;
        cin >> n;
        vector<int> fence(n);
        for (int &height : fence)
            cin >> height;

        cout << solve(fence, 0, n - 1) << '\n';
    }
}