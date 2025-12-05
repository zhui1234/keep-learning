#include <iostream>
#include <cstdio>
using namespace std;

int f[31][466][31];
bool check(int n,int k)
{
    int g[30]={0},num=0;
    for(int i=1;i<=n;i++)
        g[i]=g[i-1]+f[n][k][i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
        {
            if(g[i]-g[j]==0)return 0;
            num+=(g[i]-g[j]>0);
        }
    return num==k;
}
int t,n,k;
void init()
{
    f[1][1][1]=1;
    f[1][0][1]=-1;
    f[2][3][1]=1,f[2][3][2]=1;
    f[2][2][1]=2,f[2][2][2]=-1;
    f[2][1][1]=1,f[2][1][2]=-2;
    f[2][0][1]=-1,f[2][0][2]=-1;
    for(int i=3;i<=30;i++)
    {
        int x=i*(i+1)/2;
        for(int k=1;k<=i;k++)
            f[i][x][k]=1,f[i][0][k]=-1;
        for(int j=1;j<=i;j++)
        {
            for(int k=1;k<i;k++)
                f[i][x-j][k]=1,f[i][j][k]=-1;
            f[i][x-j][i-j]=2,f[i][j][i-j]=-2;
            f[i][x-j][i]=-j,f[i][j][i]=j;
        }
        for(int j=i+1;j<x-i;j++)
        {
            for(int k=1;k<i;k++)
                f[i][j][k]=f[i-1][j][k];
            f[i][j][i]=-i;
        }
            
    }/*
    for(int i=1;i<=30;i++)
        for(int j=1;j<=i*(i+1)/2;j++)
        {
            if(!check(i,j))
                cout<<i<<' '<<j<<endl;
        }*/
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cout<<f[n][k][i]<<' ';
    cout<<'\n';
}

int main()
{
    //freopen("test.in","r",stdin);
    init();
    cin>>t;
    while(t--)
        solve();
    return 0;
}
