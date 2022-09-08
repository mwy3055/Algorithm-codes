#include <bits/stdc++.h>

int n;
std::vector<std::string> words;

void getinput()
{
    words.clear();
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        words.push_back(s);
    }
}

char ith_char(std::string &s, int i)
{
    if (i < s.size())
        return s[i];
    else
        return '\0';
}

// cur을 prefix로 갖는 단어들이 공통으로 갖는 글자.
// 없으면 \0 반환
bool can_auto(std::string &cur, int i)
{
    std::unordered_set<char> set;
    for (auto &w : words)
    {
        if (w.substr(0, cur.size()) == cur)
            set.insert(ith_char(w, i));
    }
    return set.size() == 1;
}

// 이 문자열의 다음 글자?
void preprocess(std::unordered_map<std::string, char> &m)
{
    for (auto &w : words)
    {
        std::string substr;
        for (int i = 1; i <= w.size(); i++)
        {
            substr.push_back(w[i - 1]);
            auto ith = ith_char(w, i);
            // 없다면 넣는다
            if (!m.count(substr))
                m[substr] = ith;
            // 있는데 다르다면 null로 바꾼다
            else if (m[substr] != '\0' && m[substr] != ith)
                m[substr] = '\0';
        }
    }
}

double solve()
{
    std::unordered_map<std::string, char> m;
    preprocess(m);

    double sum = 0;
    for (auto &w : words)
    {
        std::string cur;
        for (int i = 0; i < w.size(); i++)
        {
            if (i == 0 || m[cur] == '\0')
                sum++;
            cur.push_back(w[i]);
        }
    }
    return sum / n;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cout.precision(2);
    while (std::cin >> n)
    {
        getinput();
        std::cout << std::fixed << solve() << '\n';
    }
}