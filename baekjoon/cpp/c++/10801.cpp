#include <cstdio>
using namespace std;

int main()
{
    int a[10], b[10], A = 0, B = 0;
    for (int i = 0; i < 10; i++)
        scanf("%d", a + i);
    for (int i = 0; i < 10; i++)
        scanf("%d", b + i);
    for (int i = 0; i < 10; i++)
    {
        if (a[i] < b[i])
            B++;
        else if (a[i] > b[i])
            A++;
    }
    if (A < B)
        printf("B");
    else if (A > B)
        printf("A");
    else
        printf("D");
}