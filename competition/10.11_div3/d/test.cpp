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
inline long long Min(long long a,long long b){return a<=b?a:b;}
const int N=200010;
int t,n;
string s;
long long ans,l[N],r[N];
int p[N],num;
long long work(char c)
{
	ans=0x7fffffff;
	num=0;
	for(int i=0;i<n;i++)
		if(s[i]==c)
			p[++num]=i;
	l[1]=r[num]=0;
	for(int i=2;i<=num;i++)
		l[i]=l[i-1]+(p[i]-1-p[i-1])*(i-1);
	for(int i=num-1;i>=1;i--)
		r[i]=r[i+1]+(p[i+1]-p[i]-1)*(num-i);
	for(int i=1;i<=num;i++)
		ans=Min(ans,l[i]+r[i]);
	return ans;
}

int main()
{
	//freopen("test.in","r",stdin);
	t=read();
	while(t--)
	{
		n=read();
		getline(cin,s);
		printf("%lld\n",Min(work('a'),work('b')));
	}
	return 0;
}
