#include <iostream>
#include <cstdio>
using namespace std;

int t;
string s;
int p[10],num;
void solve()
{
    cin>>s;
    for(int i=0;i<10;i++)
        p[i]=0;
    num=0;
    for(int i=0;i<4;i++)
        p[s[i]-'0']++;
    int last=0;
    for(int i=0;i<10;i++)
        if(p[i])
        {
            num++;
            if(p[i]==2 && i!=last && p[last]==2)
            {
                puts("4");
                return;
            }
            last=i;
        }
    switch (num)
    {
        case 1:
            puts("-1");
            break;
        case 2:
            puts("6");
            break;
        case 3:
            puts("4");
            break;
        default:
            puts("4");
            break;
    }
}


int main()
{
    //freopen("test.in","r",stdin);
    cin>>t;
    while(t--)
        solve();
    return 0;
}
