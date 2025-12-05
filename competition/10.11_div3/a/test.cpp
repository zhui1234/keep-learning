#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int sum=0,p=1;
	char c=getchar();
	while(c<'0'|| c>'9')
	{	
		if(c=='-')p=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')sum=(sum<<1)+(sum<<3)+(c^48),c=getchar();
	return sum*p;
}
int t,n;
int x,num,ans;

int main()
{
	//freopen("test.in","r",stdin);
	t=read();
	while(t--)
	{
		n=read();
		num=ans=0;
		while(n--)
		{
			x=read();
			if(x==0)
				ans++;
			else
				if(x==-1)
					num++;
		}
		if(num&1)ans+=2;
		printf("%d\n",ans);
	}
	return 0;
}
