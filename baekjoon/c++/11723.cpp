#include <cstdio>
using namespace std;

int main()
{
    int m, x;
    char op[10];
    bool s[20] = {false};
    scanf("%d", &m);
    while (m--)
    {
        scanf("%s", &op);
        if (op[1] == 'l')
            for (int i = 0; i < 20; i++)
                s[i] = true;
        else if (op[1] == 'm')
            for (int i = 0; i < 20; i++)
                s[i] = false;
        if (!scanf("%d", &x))
            continue;
        if (op[1] == 'd')
            s[x - 1] = true;
        else if (op[1] == 'e')
            s[x - 1] = false;
        else if (op[1] == 'h')
            printf("%d\n", s[x - 1]);
        else if (op[1] == 'o')
            s[x - 1] = !s[x - 1];
    }
}