#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
using i64 = long long;

const int N=200010;
int t,n;
i64 a[N],b[N],sum[N],ans[N][2];
void solve()
{
    memset(ans,0,sizeof(ans));
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i],sum[i]=sum[i-1]+b[i];
    for(int i=1;i<=n;i++)
    {
        int l=i,r=n;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(sum[mid]-sum[i-1] >= a[i])
                r=mid;
            else
                l=mid+1;
        }
        ans[i][1]++,ans[l][1]--;
        ans[l][0]+=min(b[l],a[i]-sum[l-1]+sum[i-1]);
        
    }
    for(int i=1;i<=n;i++)
        ans[i][1]+=ans[i-1][1];
    for(int i=1;i<=n;i++)
        cout<<ans[i][0]+b[i]*ans[i][1]<<' ';
    cout<<'\n';
}

int main()
{
    //freopen("test.in","r",stdin);
    cin>>t;
    while(t--)
        solve();
    return 0;
}
