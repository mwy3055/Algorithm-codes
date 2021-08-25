#include <bits/stdc++.h>

int ni, mj;
char pixel[1000][1001];

void getinput()
{
    std::cin >> ni >> mj;
    for (int i = 0; i < ni; i++)
    {
        std::cin >> pixel[i];
    }
}

bool height_check(int multip)
{
    for (int k = 0; k < mj; k++)
    {
        for (int i = 0; i < ni; i += multip)
        {
            for (int j = 1; j < multip; j++)
            {
                if (pixel[i][k] != pixel[i + j][k])
                    return false;
            }
        }
    }
    return true;
}

int height_div()
{
    if (height_check(ni))
        return ni;
    int div = 1;
    for (int i = 2; i <= ni / 2; i++)
    {
        // i배 늘렸는가?
        if (ni % i == 0 && height_check(i))
            div = i;
    }
    return div;
}

bool width_check(int multip)
{
    for (int k = 0; k < ni; k++)
    {
        for (int i = 0; i < mj; i += multip)
        {
            for (int j = 1; j < multip; j++)
            {
                if (pixel[k][i] != pixel[k][i + j])
                    return false;
            }
        }
    }
    return true;
}

int width_div()
{
    if (width_check(mj))
        return mj;
    int div = 1;
    for (int i = 2; i <= mj / 2; i++)
    {
        if (mj % i == 0 && width_check(i))
            div = i;
    }
    return div;
}

void solve()
{
    int hdiv = height_div(), wdiv = width_div();
    int height = ni / hdiv, width = mj / wdiv;
    std::cout << height << ' ' << width << '\n';
    for (int i = 0; i < ni; i += hdiv)
    {
        for (int j = 0; j < mj; j += wdiv)
            std::cout << pixel[i][j];
        std::cout << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}