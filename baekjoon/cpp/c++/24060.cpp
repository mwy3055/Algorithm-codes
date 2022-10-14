#include <bits/stdc++.h>

int n, k;
std::vector<int> a, b;

void getinput()
{
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        a.push_back(num);
    }
}

bool solved = false;
int num = -1, count = 0;

void put(int index, int val)
{
    b[index] = val;
    count++;
    if (count == k)
    {
        solved = true;
        num = val;
    }
}

void merge(int l, int mid, int r)
{
    int i = l, j = mid + 1, index = l;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            put(index++, a[i++]);
        }
        else
        {
            put(index++, a[j++]);
        }
    }

    while (i <= mid)
        put(index++, a[i++]);
    while (j <= r)
        put(index++, a[j++]);

    int midx = l;
    while (midx <= r)
    {
        a[midx] = b[midx];
        midx++;
    }
}

// [l, r]
void merge_sort(int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, mid, r);
}

int solve()
{
    b.resize(n, 0);

    merge_sort(0, n - 1);
    return num;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}