#include<iostream>
#include<cstdio>
using namespace std;

int t,n;
int a[20],b[20],c[20];
int Log[1100];
bool pd()
{
    for(int i=2;i<=b[0];i++)
        if(a[b[i]]<a[b[i-1]])
            return 0;
    return 1;
}
bool Pd()
{
    int l=1,r=n;
    while(l<=r)
    {
        while(c[l] && l<=r)l++;
        while(c[r] && l<=r)r--;
        if(l>r)break;
        if(a[l]!=a[r])return 0;
        l++,r--;
    }
    return 1;
}
void Print()
{
    printf("%d\n",b[0]);
    for(int i=1;i<=b[0];i++)
        printf("%d ",b[i]);
    printf("\n");
}

int main()
{
    //freopen("test.in","r",stdin);
    scanf("%d\n",&t);
    for(int i=2;i<=1024;i*=2)Log[i]=Log[i>>1]+1;
    while(t--)
    {
        scanf("%d\n",&n);
        bool p=0;
        for(int i=1;i<=n;i++)  
            scanf("%1d",&a[i]);
        for(int i=(1<<n)-1;i>=0;i--)//0000 ~ 1111
        {
            b[0]=0;
            int x=i,y;
            while(x)
            {
                y=x&(-x);
                x-=y;
                b[++b[0]]=Log[y]+1;//b[]:record i th position that will be removed 
            }
            if(!pd())continue;
            for(int j=1;j<=n;j++)c[j]=0;//c[i]=0 represent i th position is not removed
            for(int j=1;j<=b[0];j++)c[b[j]]=1;
            if(Pd())
            {
                Print();
                p=1;
                break;
            }
        }
        if(!p)
            printf("-1\n");
    }
    return 0;
}
