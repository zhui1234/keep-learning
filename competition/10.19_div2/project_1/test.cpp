#include<iostream>
#include<cstdio>
using namespace std;

int t,n,k;
int ans;

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ans=0;
        int x,last=-2000;
        for(int i=1;i<=n;i++)
        {
            scanf("%1d",&x);
            if(!x)continue;
            if(i-last>=k)ans++;
            last=i;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
si=1,
si is not protected,
1 does not occur in smax(1,i−k+1),…,si−1
.*/