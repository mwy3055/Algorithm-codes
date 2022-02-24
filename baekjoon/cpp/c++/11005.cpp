#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n,b;
    cin>>n>>b;

    stack<char> s;
    while(n)
    {
        int rmd=n%b;
        if(rmd<10)
        s.push('0'+rmd);
        else
        {
            s.push('A'+(rmd-10));
        }
        n/=b;
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}