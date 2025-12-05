#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int t,n;
char c;
map<char,int> mp;

int main()
{
    //freopen("test.in","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool p=0;
        for(int i='a';i<='z';i++)
            mp[i]=0;
        for(int i=0;i<n;i++)
        {
            cin>>c;
            mp[c]++;
        }
        for(int i=0;i<n;i++)
        {
            cin>>c;
            mp[c]--;
        }
        for(auto it:mp)
            if(it.second!=0)
            {
                p=1;break;
            }
        if(p)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
