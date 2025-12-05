#include<iostream>
#include<cstdio>
using namespace std;

const int N=200010;
int t,n;
int a[N];
void Print(int S,int T)
{
    cout<<abs(S-T)<<'\n'<<S;
    for(int i=2;i<n;i++)    
        cout<<' '<<((a[i]!=-1)?a[i]:0);
    cout<<' '<<T<<'\n';
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(a[1]==-1 && a[n]==-1)
        Print(0,0);
    else
        if(a[1]!=-1 && a[n]!=-1)
            Print(a[1],a[n]);
        else
            if(a[1]!=-1)
                Print(a[1],a[1]);
            else
                Print(a[n],a[n]);
}

int main()
{
    //freopen("test.in","r",stdin);
    cin>>t;
    while(t--)
        solve();
    return 0;
}
