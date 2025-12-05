#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int t;
int n;
int a[110],head,tail;
int ans;

int main()
{
    //freopen("test.in","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=0,a[n+1]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        head=1,tail=n;
        while(a[head]==1 && head<=tail)
        {
            ans++;
            a[++head]--;
            if(!a[head] && head<=tail)
                head++;
        }
        ans+=tail-head+1;
        printf("%d\n",ans);
    }
    return 0;
}
