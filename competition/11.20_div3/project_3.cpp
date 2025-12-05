#include<iostream>
#include<cstdio>
using namespace std;

const int N=200010;
int t,n,x;
int num1,num2;
int a[N],b[N],now;
void solve()
{
    cin>>n;
    now=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)
        if(a[i]!=b[i])
        {
            if(i&1)
            {
                if(now==0)now=-1;
                else now=0;
            }
            else
            {
                if(now==0)now=1;
                else now=0;
            }
        }
    if(now==0)
        puts("Tie");
    else
        if(now==1)
            puts("Mai");
        else
            puts("Ajisai");
}

int main()
{
    //freopen("test.in","r",stdin);
    cin>>t;
    while(t--)
        solve();
    return 0;
}
