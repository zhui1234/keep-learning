#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int t,n,k,l,r;
int f[60];
bool pd()
{
    if(!f[k])
        return 0;
    for(int i=1;i<=50;i++)
        if(i!=k && f[i]==f[k])
            return 0;
    return 1;
}
void solve ()
{
    memset(f,0,sizeof(f));
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r;
        if(l <= k && k <= r)
            f[l]++,f[r+1]--;
    }
    for(int i=1;i<=50;i++)
        f[i]+=f[i-1];
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
