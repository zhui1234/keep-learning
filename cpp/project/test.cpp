#include<iostream>
using namespace std;

class Box
{
    private:
        double length,width,height;
    public:
        static int num;
        Box(double l,double w,double h):length(l),width(w),height(h)  //构造函数
        {
            num++;
        }
        double get_volume();
};
int Box::num=0; //初始化静态成员变量

double Box::get_volume()
{
    return length*width*height;
}

int main()
{
    Box Box1(1.0,2.0,3.0);
    cout<<Box1.get_volume()<<'\n'<<Box::num;
    return 0;
}