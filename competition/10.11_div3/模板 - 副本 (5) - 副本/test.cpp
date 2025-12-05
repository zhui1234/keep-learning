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
int main()
{
	freopen("test.in","r",stdin);
	return 0;
}
