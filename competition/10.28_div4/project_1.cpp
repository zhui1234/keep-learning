#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    //freopen("test.in","r",stdin);
    int n,a,b,c,d;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c>>d;
        if(a==b && b==c && c==d)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
