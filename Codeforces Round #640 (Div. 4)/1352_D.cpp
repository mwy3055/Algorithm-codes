#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        deque<int> candies(n);
        for (auto &candy : candies)
            cin >> candy;

        int a = 0, b = 0, preva = 0, prevb = 0, count = 0;
        for (int i = 0; !candies.empty(); i++)
        {
            count++;
            if (i % 2 == 0) // alice
            {
                int cnt = 0;
                do
                {
                    cnt += candies.front();
                    candies.pop_front();
                } while (!candies.empty() && cnt <= prevb);
                a += cnt;
                preva = cnt;
            }
            else
            {
                int cnt = 0;
                do
                {
                    cnt += candies.back();
                    candies.pop_back();
                } while (!candies.empty() && cnt <= preva);
                b += cnt;
                prevb = cnt;
            }
        }
        cout << count << ' ' << a << ' ' << b << '\n';
    }
}