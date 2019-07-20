int GCD(int a, int b)
{
    //ºÒº¯½Ä: a <= b
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b % a)
        return GCD(a, b % a);
    else
        return a;
}