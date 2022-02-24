#include <bits/stdc++.h>
using namespace std;

struct student
{
    int ko, eng, math;
    string name;
};

bool compare(const student &a, const student &b)
{
    if (a.ko != b.ko)
        return a.ko > b.ko;
    if (a.eng != b.eng)
        return a.eng < b.eng;
    if (a.math != b.math)
        return a.math > b.math;
    return a.name <= b.name;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    student *s = new student[n];
    for (int i = 0; i < n; i++)
        cin >> s[i].name >> s[i].ko >> s[i].eng >> s[i].math;

    sort(s, s + n, compare);
    for (int i = 0; i < n; i++)
        cout << s[i].name << '\n';

    delete[] s;
}