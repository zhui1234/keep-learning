#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int sum=0;
	char c=getchar();
	while(c<'0'|| c>'9')c=getchar();
	while(c>='0' && c<='9')sum=(sum<<1)+(sum<<3)+(c^48),c=getchar();
	return sum;
}
int t,n,k;
int a[200010],ans; 

int main()
{
	//freopen("test.in","r",stdin);
	t=read();
	while(t--)
	{
		n=read(),k=read();
		ans=0; 
		for(int i=0;i<=k;i++)a[i]=0;
		for(int i=1;i<=n;i++)
		{
			int x=read();
			a[x]++;
		}
		for(int i=0;i<k;i++)
			if(!a[i])
				ans++;
		printf("%d\n",max(ans,a[k]));
	}
	return 0;
}
