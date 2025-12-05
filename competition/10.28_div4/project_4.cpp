#include<iostream>
#include<cstdio>
using namespace std;

int t,n;
long long a[100005];

int main()
{
    //freopen("test.in","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
    } 
    return 0;
}
