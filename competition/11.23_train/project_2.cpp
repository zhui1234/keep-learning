#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
using ll=long long;

int t;
ll n;
void solve()
{
    cin>>n;
    double x=sqrt(n);
    ll ans=ceil(x);
    if(ans*ans<n)
        ans++;
    cout<<ans-1<<endl;
}

int main()
{
    //freopen("test.in","r",stdin);
    cin>>t;
    while(t--)
        solve();
    return 0;
}
