#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int t,n;
int a[200005];

int main()
{
    //freopen("test.in","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool p1=0,p2=0;
        for(int i=1;i<=n;i++) 
            cin>>a[i],p1=p1|(a[i]&1),p2=p2|(!(a[i]&1));
        if(p1 && p2)
        {
            sort(a+1,a+n+1);
            for(int i=1;i<=n;i++) 
                cout<<a[i]<<" ";
        }
        else
        {
            for(int i=1;i<=n;i++) 
                cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
