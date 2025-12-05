#include<iostream>
#include<cstdio>
using namespace std;

int t,n,m;
char a[50];
bool pd()
{
    int p=0;
    for(int i=2;i<=n+m;i++)
        if(a[i]==a[i-1])
            p++;
    return p<=1;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n+m;i>n;i--)
        cin>>a[i];
    puts(pd()?"YES":"NO");
}

int main()
{
    //freopen("test.in","r",stdin);
    cin>>t;
    while(t--)
        solve();
    return 0;
}
