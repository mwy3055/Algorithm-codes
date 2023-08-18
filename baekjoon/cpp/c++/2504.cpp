#include <iostream>
#include <stack>
#include <string>
using namespace std;

typedef struct bracket //°ýÈ£
{
    char c;
    int val, idx;
} br;

const int RVALUE = 2, SVALUE = 3;

bool isCorrect(string &s)
{
    stack<char> st;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '[')
            st.push(s[i]);
        else if ((s[i] == ')' && !st.empty() && st.top() == '(') || s[i] == ']' && !st.empty() && st.top() == '[')
            st.pop();
        else
            return false;
    }
    return st.size() == 0;
}

int solve(string &s)
{
    stack<br> st;
    int len = s.length(), ans = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '[')
            st.push(br{s[i], 0, i});
        else
        {
            int VALUE = s[i] == ')' ? RVALUE : SVALUE;
            br &top = st.top();
            st.pop();
            if (top.idx + 1 == i)
            {
                if (st.size() != 0)
                    st.top().val += VALUE;
                else
                    ans += VALUE;
            }
            else
            {
                if (st.size() != 0)
                    st.top().val += top.val * VALUE;
                else
                    ans += top.val * VALUE;
            }
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    if (!isCorrect(s))
    {
        cout << 0;
        return 0;
    }

    cout << solve(s);
}