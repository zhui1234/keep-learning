#include<iostream>
#include<cstdio>
using namespace std;
using i64=long long;

const int Mod=998244353;
int n;
int a1,a2,a3;
i64 ans=1;
void Swap(int& x,int& y)
{
    x^=y;
    y^=x;
    x^=y;
}
void Sort(int& a1,int& a2,int& a3)
{
    if(a1>a2)
        Swap(a1,a2);
    if(a2>a3)
        Swap(a2,a3);
    if(a1>a2)
        Swap(a1,a2);
    
}
i64 Pow(i64 a,int b)
{
    i64 num=1;
    while(b)
    {
        if(b&1)num=num*a%Mod;
        a=a*a%Mod;
        b>>=1;
    }
    return num;
}
i64 comb(int n)
{
    n/=2;
    i64 num=1;
    for(int i=1;i<=n;i++)
    {
        num=num * (n+i) % Mod;
        num=num * Pow(i,Mod-2) % Mod;
    }
    return num;
}

int main()
{
    //freopen("test.in","r",stdin);
    cin>>n;
    n/=3;
    for(int i=1;i<=n;i++)
    {
        cin>>a1>>a2>>a3;
        Sort(a1,a2,a3);
        if(a1==a2 && a2==a3){ans=ans*3%Mod;continue;}
        if(a1==a2){ans=ans*2%Mod;continue;}
    }
    cout<<ans*comb(n)%Mod;
    return 0;
}
