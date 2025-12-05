#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

const int Max=(1<<30);
int t,a,b;
map<int,int>Log;
int highbit(int x)
{
	int y;
	while(x)
	{
		y=x&(-x);
		x-=y;
	}
	return y;
}
int ans[110];

int main()
{
    //freopen("test.in","r",stdin);
    cin>>t;
    for(int i=1;i<=27;i++)
		Log[1<<i]=Log[1<<(i-1)]+1;
    while(t--)
    {
		cin>>a>>b;
		if(a<b){puts("-1");continue;}
		ans[0]=0;
		int ha=highbit(a),hb=highbit(b);
		if(ha>hb)
		{
			ans[++ans[0]]=a^((1<<(Log[ha]+1))-1);
			a=(1<<(Log[ha]+1))-1;
		}
		while(ha>hb)
		{
			a-=ha;
			ans[++ans[0]]=ha;
			ha>>=1;
		}
		ans[++ans[0]]=a^b;
		printf("%d\n",ans[0]);
		for(int i=1;i<=ans[0];i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
    return 0;
}
