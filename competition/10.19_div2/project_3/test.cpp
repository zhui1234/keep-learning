#include<iostream>
#include<cstdio>
using namespace std;

const int N=200010;
int t,n;
int a[N],b[N];
int p[N],prime[N];
int appear[N];
bool work(int now,int last)
{
    if(now==1)return 0;
    while(p[now])
    {
        if(p[now]>last)last=p[now],appear[last]++;
        if(appear[last]==2) return 1;
        now=now/p[now];
    }
    if(now>last)
        appear[now]++;
    return appear[now]>=2;
}
bool Work(int now)
{
    while(p[now])
    {
        if(appear[p[now]])return 1;
        now/=p[now];
    }
    return appear[now]>0;
}

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    for(int i=2;i<N;i++)
    {
        if(!p[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0] && i*prime[j]<N;j++)
        {
            p[i*prime[j]]=prime[j];
            if(i%prime[j]==0)break;
        }
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool P=0;
        for(int i=2;i<N;i++)appear[i]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(!P)
                P=work(a[i],0);
        }
        for(int i=1;i<=n;i++)cin>>b[i];
        if(P){puts("0");continue;}
        for(int i=1;i<=n && !P;i++)
            P=Work(a[i]+1);
        if(P)puts("1");
        else puts("2");
    }
    return 0;
}
// t:10^4 n:2*10^5