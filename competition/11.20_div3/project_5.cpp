#include<iostream>
#include<cstdio>
using namespace std;

const int N=200010;
int t,n;
int a[N];
struct edge
{
    int to,next;
}e[N<<2];
int head[N],tot;
int v[N];
void add(int u,int v)
{
    e[++tot].to=v;
    e[tot].next=head[u];
    head[u]=tot;
}
void dfs(int x)
{
    if(v[x])
        return;
    v[x]=1;
    for(int i=head[x];i;i=e[i].next)
        dfs(e[i].to);
}
bool pd()
{
    dfs(1);
    for(int i=1;i<=n;i++)
        if(!v[i]){
            cout<<i<<endl;
            return 0;
        }
    return 1;
}
void solve()
{
    cin>>n;
    int minn=n+1,maxx=0;
    tot=0;
    for(int i=1;i<=n;i++)head[i]=v[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<minn)
           minn=a[i];
        else
           add(a[i],minn),add(minn,a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        if(a[i]>maxx)
           maxx=a[i];
        else
           add(a[i],maxx),add(maxx,a[i]);
    }
    if(pd())
        puts("Yes");
    else
        puts("No");
}

int main()
{
    freopen("test.in","r",stdin);
    cin>>t;
    while(t--)
        solve();
    return 0;
}
