#include <bits/stdc++.h>
using namespace std;

void SWAP(int a, int b, int *wood)
{
    int temp = wood[a];
    wood[a] = wood[b];
    wood[b] = temp;
    for (int i = 0; i < 5; i++)
        printf("%d ", wood[i]);
    printf("\n");
}

bool check(int *wood)
{
    for (int i = 0; i < 5; i++)
    {
        if (wood[i] != i + 1)
            return false;
    }
    return true;
}

int main()
{
    int wood[5];
    for (int i = 0; i < 5; i++)
        scanf("%d", wood + i);

    do
    {
        if (wood[0] > wood[1])
            SWAP(0, 1, wood);
        if (wood[1] > wood[2])
            SWAP(1, 2, wood);
        if (wood[2] > wood[3])
            SWAP(2, 3, wood);
        if (wood[3] > wood[4])
            SWAP(3, 4, wood);
    } while (!check(wood));
}