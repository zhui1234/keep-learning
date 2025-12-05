# 2.类(图形输出)

## 2.1.结构

```C++
class 类名
{
    类访问修饰符:
        (static) 变量类型 (静态)变量/函数
        类名(参数):{} //构造函数
};
```

## 2.2.类访问修饰符

> `private` 在类的外部不可访问,需要使用成员函数来访问和修改,无访问修饰符默认为私有成员
> `public` 在类的外部可访问,可以不使用成员函数来访问和修改
> `protected` 与`private`类似,但可以在派生类访问和修改

## 2.3.特殊符号

> `.` 访问类的public成员 用法: 对象.成员变量/函数
> `::` 访问类的静态成员/在类外部定义成员函数 类名::静态成员名/函数

## 2.4.静态成员

> 在所有对象间共享
> 必须在类外初始化

## 2.5.示例

```C++
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
```
