#include<iostream>
#include<cstdio>
using namespace std;

int t;
int a[4];

int main()
{
    //freopen("test.in","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        int ans=0;
        for(int i=0;i<4;i++)
            scanf("%d",&a[i]);
        if(!a[0])
            ans=1;
        else
        {
            ans+=min(a[1],a[2])*2;
            a[3]+=a[1]+a[2]-ans;
            if(a[0]>=a[3])
                ans+=a[0]+a[3];
            else
                ans+=a[0]*2+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
