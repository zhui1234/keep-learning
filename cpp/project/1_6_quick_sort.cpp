#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void Swap(int& a,int& b)
{
	a=a^b;
	b=b^a;
	a=a^b;
}

void Getmid(vector<int>& a,int l,int r) // 比较左、中、右三个位置的值，以中间值为基准值
{
	int mid=(l+r)>>1;
	if(a[l]>a[mid])
		Swap(a[l],a[mid]);
	if(a[l]>a[r])
		Swap(a[l],a[r]);
	if(a[mid]<a[r])
		Swap(a[mid],a[r]);
}
int Partition(vector<int>& a,int l,int r)
{
	Getmid(a,l,r);
	int stand=r; // 以右端为基准划分
	while(l<r)
	{
		while(a[l]<=a[stand] && l<r)l++; // 先移动左指针,确保l==r时a[l]>a[stand]
		while(a[r]>=a[stand] && l<r)r--;
		if(l<r)
			Swap(a[l],a[r]);
	}
	Swap(a[l],a[stand]);
	return l;
}
void Quicksort(vector<int>& a,int l,int r) // 写了递归,还是觉得非递归实现更好
{
	stack<pair<int,int>> s;
	s.push({l,r});
	while(!s.empty())
	{
		pair<int,int> now=s.top();
		s.pop();
		l=now.first,r=now.second;
		
		int p=Partition(a,l,r);
		if(l<p-1) // 避免使用vector越界索引而出错
			s.push({l,p-1});
		if(p+1<r)
			s.push({p+1,r});
	}
}
/*
void Quicksort(vector<int>& a,int l,int r) // 递归实现
{
	if(l>=r)return;
	int p=partition(a,l,r);
	Quicksort(a,l,p-1);
	Quicksort(a,p+1,r);
}
*/

void Input(int& n,vector<int>& a)
{
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
}
void Print(int& n,vector<int>& a)
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}

int n;
vector<int> a;

int main()
{
	//freopen("test.in","r",stdin);
	Input(n,a);
	Quicksort(a,0,n-1);
	Print(n,a); 
	return 0;
}
