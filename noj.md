# noj

## T11

```c++
#include<iostream>
#include<cstdio>
using namespace std;

int Abs(int x)
{
    return x>=0?x:-x;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",Abs(j-i));
        printf("\n");
    }
    return 0;
}
```

## T12

```C++
#include<iostream>
#include<cstdio>
using namespace std;

int Abs(int x)
{
    return x>=0?x:-x;
}

int main()
{
    int n,num=0;
    scanf("%d",&n);
    for(int i=0;i<=9;i++)
    for(int j=0;j<=9;j++)
    for(int k=0;k<=9;k++)
    for(int l=0;l<=9;l++)
    if(i+j+k+l==n)
        num++;
    cout<<num;
    return 0;
}
```

## T13

```C++
#include<iostream>
#include<cstdio>
using namespace std;

int Abs(int x)
{
    return x>=0?x:-x;
}
int gcd(int x,int y)
{
    if(x<y)swap(x,y);
    if(!y)return x;
    return gcd(y,x%y);
}

int main()
{
    int a,b,c,d;
    scanf("%d/%d\n%d/%d",&a,&b,&c,&d);
    int a1=a*d,a2=c*b;
    printf("(%d/%d)+(%d/%d)=%d/%d\n",a,b,c,d,(a1+a2)/gcd(a1+a2,b*d),b*d/gcd(a1+a2,b*d));
    printf("(%d/%d)-(%d/%d)=%d/%d\n",a,b,c,d,(a1-a2)/gcd(Abs(a1-a2),b*d),b*d/gcd(Abs(a1-a2),b*d));
    printf("(%d/%d)*(%d/%d)=%d/%d\n",a,b,c,d,a*c/gcd(a*c,b*d),b*d/gcd(a*c,b*d));
    printf("(%d/%d)/(%d/%d)=%d/%d\n",a,b,c,d,a*d/gcd(a*d,b*c),b*c/gcd(a*d,b*c));
    return 0;
}
```

## T14

```C++
#include<iostream>
#include<cstdio>
using namespace std;

int Abs(int x)
{
    return x>=0?x:-x;
}
int gcd(int x,int y)
{
    if(x<y)swap(x,y);
    if(!y)return x;
    return gcd(y,x%y);
}
long long a,b,m;
long long ans;

int main()
{
    cin>>a>>b>>m;
    a%=m,b%=m;
    while(b)
    {
        if(b&1)
        {
            ans=(ans+a)%m;
            b--;
        }
        a=(a<<1)%m;
        b >>= 1;
    }
    cout<<ans;
    return 0;
}
```

## T15

```C++
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

long long a,b,m,ans=1;

int main()
{
    //freopen("test.in","r",stdin);
    cin>>a>>b>>m;
    //a%=m,b%=m;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%m;
        a=(a*a)%m;
        b >>=1;
    }
    cout<<ans;
    return 0;
}
```

## T16

```C++
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n;
double x=0.2,d=1,ans=1.2;

int main()
{
    //freopen("test.in","r",stdin);
    cin>>n;
    cout<<1.2;
    for(int i=2;i<=n;i++)
    {
        if(i<9)
            x=(i+1)*1.0/10;
        else
            x=(i+1)*1.0/100;
        cout<<'+'<<i+x;
        ans+=i+x;
    }
    cout<<'='<<ans;
    return 0;
}
```

## T17

```C++
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n;
int num(int x)
{
    int sum=0;
    while(x)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}

int main()
{
    //freopen("test.in","r",stdin);
    cin>>n;
    for(int i=1;;i++)
    {
        n-=num(n);
        if(n<=0)
        {
            cout<<i;
            break;
        }
    }
    return 0;
}
```

## T18

```C++
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int gcd(int a,int b)
{
    if(a<b)swap(a,b);
    if(!b)return a;
    return gcd(b,a%b);
}

int main()
{
    //freopen("test.in","r",stdin);
    double x;
    cin>>x;
    if(x<0)
    {
        cout<<'-';
        x=-x;
    }
    int a,b=1,d;
    while(x-floor(x) > 1e-9)
    {
        x*=10;
        b*=10;
    }
    a=(int)x;
    d=gcd(a,b);
    a/=d;
    b/=d;
    cout<<a<<'/'<<b<<endl;
    return 0;
}
```

## T19

```C++
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

string s;
int h,t;
bool p;

int main()
{
    //freopen("test.in","r",stdin);
    getline(cin,s);
    t=s.size()-1;
    while(h<t)
    {
        if(s[h]==s[t])
        {
            if(!(s[h]=='0' || s[h]=='1' || s[h]=='8'))
            {
                p=1;
                break;
            }
        }
        else
        {
            if(!(s[h]=='9' && s[t]=='6' || s[h]=='6' && s[t]=='9'))
            {
            p=1;
            break;}
        }
        h++,t--;
    }
    if(h==t)
        if(!(s[h]=='0' || s[h]=='1' || s[h]=='8'))
            p=1;
    if(p)
        cout<<"No";
    else
        cout<<"Yes";
    return 0;
}
```

## T20

```C++
#include<iostream>
#include<cstdio>
#include<cmath>
#include<regex>
#include<cstring>
using namespace std;

int t,n;

int main()
{
    //freopen("test.in","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int sum=0;
        for(int i=1;i<n;i++)
            if(i%3==0 || i%5==0)
                sum+=i;
        cout<<sum<<endl;
    }
    return 0;
}
```
