#include<iostream>
#include<cstdio>
using namespace std;

int t,n;
void solve()
{
    cin>>n;
    if(n&1)
    {
        puts("0");
        return;
    }
    cout<<n/4+1<<endl;
}

int main()
{
    //freopen("test.in","r",stdin);
    cin>>t;
    while(t--)
        solve();
    return 0;
}
