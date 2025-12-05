#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int sum=0,p=1;
	char c=getchar();
	while(c<'0'|| c>'9')p=(c=='-')?-1:1,c=getchar();
	while(c>='0' && c<='9')sum=(sum<<1)+(sum<<3)+(c^48),c=getchar();
	return sum*p;
}
inline int Max(int a,int b){return a>=b?a:b;}
inline int Abs(int a){return a>=0?a:-a;}
int t,n;
int a[200010]; 
int maxx;

int main()
{
	//freopen("test.in","r",stdin);
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		maxx=0;
		for(int i=1;i<n;i+=2)
			maxx=Max(maxx,Abs(a[i]-a[i+1]));
		printf("%d\n",maxx);
	}
	return 0;
}
