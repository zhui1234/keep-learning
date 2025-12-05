#include<iostream>
#include<cstdio>
using namespace std;

int t,n;

int main()
{
    //freopen("test.in","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n&1)
            printf("%d\n",n/2);
        else
            printf("%d\n",n/2-1);
    }
    return 0;
}
