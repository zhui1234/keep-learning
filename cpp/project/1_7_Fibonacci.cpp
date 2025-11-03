#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int>a(40,1); // 斐波那契数列第40项未超过int范围

int main()
{
    cin>>n;
    cout<<"1\n1\n";
    for(int i=2;i<n;i++)
    {
        a[i]=a[i-1]+a[i-2];
        cout<<a[i]<<"\n";
    }
    return 0;
}