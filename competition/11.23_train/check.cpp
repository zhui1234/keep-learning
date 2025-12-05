#include<iostream>
#include<cstdio>

using namespace std;

int n,k;
int a[40];
int num;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]+=a[i-1];
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++){
            num+=(a[i]-a[j]>0);
            if(a[i]-a[j]==0)
                puts("error");
        }
    cout<<num;
    puts(num==k?"YES":"NO");
    return 0;
}