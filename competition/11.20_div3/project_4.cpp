#include<iostream>
#include<cstdio>
using namespace std;

const int N=200010;
int t,n;
int a[N],b[N];
int pd(int x)
{
    int now=0;
    for(int i=1;i<=n;i++)
        if((a[i]&(1<<x))!=(b[i]&(1<<x)))
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
    return now;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=19;i>=0;i--)
    {
        int now=pd(i);
        if(!now)continue;
        if(now==1)puts("Mai");
        else puts("Ajisai");
        return;
    }
    puts("Tie");
}

int main()
{
    //freopen("test.in","r",stdin);
    cin>>t;
    while(t--)
        solve();
    return 0;
}
