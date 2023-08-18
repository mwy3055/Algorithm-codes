int pi[1000000]; // length of pattern
void getpi(string &p)
{
    // pi[0] = 0
    int j = 0;
    for (int i = 1; i < p.size(); i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
}
void kmp(vector<int> &ans, string &t, string &p)
{
    int j = 0, tlen = t.size(), plen = p.size();
    for (int i = 0; i < tlen; i++)
    {
        while (j > 0 && t[i] != p[j])
            j = pi[j - 1];
        if (t[i] == p[j])
        {
            if (j == plen - 1)
            {
                ans.push_back(i - plen + 1); // index of pattern in text
                j = pi[j];
            }
            else
            {
                j++;
            }
        }
    }
}