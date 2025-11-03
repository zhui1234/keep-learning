#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Insertsort(int& n,vector<int>& a)
{
    for(int i=1;i<n;i++)
    {
        int now=a[i];
        auto site=lower_bound(a.begin(),a.begin()+i,now); // 找到从左往右第一个大于等于now的位置
        // 对vector使用lower_bound返回值类型是迭代器,不能直接用int*
        if(site!=a.begin()+i)
        {
            move_backward(site,a.begin()+i,a.begin()+i+1); // move_backward左闭右开,将site~i-1位置全部向右移动一位
            *site=now;
        }
    }
}
/*
void Insertsort(int& n,vector<int>& a)
{
    for(int i=1;i<n;i++)
    {
        int pos=i,now=a[i];
        while(a[pos-1]>now)
        {
            a[pos]=a[pos-1];
            pos--;
            if(!pos)
                break; // 避免越界
        }
        a[pos]=now;
    }
}
*/

void Input(int& n, vector<int>& a)
{
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
}
void Output(int& n,vector<int>& a)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
int n;
vector<int> a;

int main()
{
    //freopen("test.in","r",stdin);
    Input(n,a);
    Insertsort(n,a);
    Output(n,a);
    return 0;
}