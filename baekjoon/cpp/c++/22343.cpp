#include <bits/stdc++.h>
using ll = long long;
using bigbin = std::vector<bool>; // 큰 이진수. 맨 뒤가 가장 작은 자리

std::vector<int> a_pair, b_pair;

bigbin sum(bigbin &a, bigbin &b)
{
    bigbin result;
    bool carry = false;
    for (int aidx = a.size() - 1, bidx = b.size() - 1; aidx >= 0 || bidx >= 0; aidx--, bidx--)
    {
        int sum = 0;
        if (aidx >= 0)
            sum += a[aidx];
        if (bidx >= 0)
            sum += b[bidx];
        sum += carry;
        result.push_back(sum % 2);
        carry = sum >= 2;
    }
    if (carry)
        result.push_back(true);
    std::reverse(result.begin(), result.end());
    return result;
}

void twice(bigbin &b)
{
    b.push_back(false);
}

ll toint(bigbin &b)
{
    ll result = 0;
    for (int i = b.size() - 1; i >= 0; i--)
        result += (1 << (b.size() - 1 - i)) * b[i];
    return result;
}

void find_pair(std::string &s, std::vector<int> &vpair)
{
    std::stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            vpair[st.top()] = i;
            st.pop();
        }
    }
}

void init(std::string &a, std::string &b)
{
    a_pair.clear();
    b_pair.clear();
    a_pair.resize(a.size());
    b_pair.resize(b.size());
    find_pair(a, a_pair);
    find_pair(b, b_pair);
}

bigbin score(std::string &s, std::vector<int> &indices, int l, int r) // [l, r]
{
    if (l + 1 == r)
        return bigbin({true});
    int index = indices[l];
    if (index == r)
    {
        auto result = score(s, indices, l + 1, r - 1);
        twice(result);
        return result;
    }
    else
    {
        auto left_score = score(s, indices, l, index);
        auto right_score = score(s, indices, index + 1, r);
        return sum(left_score, right_score);
    }
}

int compare(bigbin &a, bigbin &b)
{
    if (a.size() > b.size())
        return 1;
    else if (a.size() < b.size())
        return -1;
    for (int i = 0; i < a.size(); i++)
    {
        const auto aa = a[i], bb = b[i];
        if (a[i] && !b[i])
            return 1;
        else if (!a[i] && b[i])
            return -1;
    }
    return 0;
}

char solve(std::string &a, std::string &b)
{
    init(a, b);

    auto a_score = score(a, a_pair, 0, a.size() - 1);
    auto b_score = score(b, b_pair, 0, b.size() - 1);
    auto cmp = compare(a_score, b_score);
    if (cmp < 0)
        return '<';
    else if (cmp > 0)
        return '>';
    else
        return '=';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        std::string a, b;
        std::cin >> a >> b;
        std::cout << solve(a, b) << '\n';
    }
}