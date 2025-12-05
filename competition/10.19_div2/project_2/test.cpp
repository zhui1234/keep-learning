#include<iostream>
#include<cstdio>
using namespace std;

const int N=200010;
int t,n;
int a[N];
int Max(int x,int y){return x>=y?x:y;}
int Min(int x,int y){return x<=y?x:y;}

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int maxx=0;
        for(int i=1;i<=n;i++)
        {    
            cin>>a[i];
            maxx=Max(maxx,a[i]);
            if(!(i&1))a[i]=maxx;
        }
        int ans=0;
        for(int i=1;i<=n;i+=2)
        {
            if(i==1) {ans+=Max(a[1]-a[2]+1,0);continue;}
            if(i==n) {ans+=Max(a[n]-a[n-1]+1,0);continue;}
            ans+=Max(a[i]-Min(a[i-1],a[i+1])+1,0);
        }
        printf("%d\n",ans);
    }

    return 0;
}

// t:10^4 n:2*10^5
/*
operation 1: replace ai with the prefix max up to i
operation 2: select an integer i (1≤i≤n) and then decrease aiby 1
*/