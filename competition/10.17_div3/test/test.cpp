#include<iostream>
#include<cstdio>
using namespace std;

int t,n;
int maxx;

int main()
{
    freopen("test.in","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int x;
        maxx=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            maxx=maxx>=x?maxx:x;
        }
        printf("%d\n",maxx);
    }
    return 0;
}