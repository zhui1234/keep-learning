#include<iostream>
#include<cstdio>
using namespace std;

int t;
int n,a,l,r;
int f[300010];

int main()
{
    //freopen("test.in","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n>>a;
        for(int i=1;i<=n;i++)
        {
            cin>>f[i];
            if(f[i]<=a && f[l]<f[i])
                l=i;
            if(f[i]>=a && (!r || f[r]==f[i]))
                r=i;
        }
        if(n-r > l-1) cout<<a+1<<'\n';
        else cout<<a-1<<'\n';
    }
    return 0;
}
