#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    srand(time(0));
    int ans=rand()%99+1,guess,num=0;//ans:1-99间的随机数 guess:用户猜测 num:猜测次数
    cout<<"=== 欢迎来到猜数字游戏! ==="<<'\n';
    cout<<"我已经想好了一个1到99之间的数字,你能猜出来吗?"<<'\n';
    do
    {
        cout<<'\n'<<"请输入你的猜测: ";
        cin>>guess;
        num++;
        switch (guess-ans)//通过guess-ans的值范围来判断大小
        {
            case 1 ... 98:
                cout<<'\n'<<"太大了,再试试!"<<'\n';
                break;
            case -98 ... -1:
                cout<<'\n'<<"太小了,再试试!"<<'\n';
                break;
            default:
                cout<<'\n'<<"恭喜你,猜对了!"<<'\n';
                break;
        }
    } while(guess!=ans);
    cout<<'\n'<<"你总共猜了"<<num<<"次!太棒了!"<<'\n';
    return 0;
}