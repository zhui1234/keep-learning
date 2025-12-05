# 6.模板

[TOC]
个人理解:对于一些与类型无关的代码,使用模板能避免程序冗杂,让一段程序能够处理多种类型

## 6.1基本语法

1. 函数模板

    ```C++
    template<typename T>
    T max(T a,T b)
    {
        return a>=b?a:b;
    }
    ```

2. 类模板

    ```c++
    template<typename T>
    class Box
    {
    private:
        T length,width,height;
    public:
        static int num;
        Box(T l,T w,T h):length(l),width(w),height(h)  //构造函数
        {
            num++;
        }
        T get_volume();
    };
    int Box::num=0; //初始化静态成员变量

    template<typename T>
    T Box::get_volume()
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

3. 其他操作
    > `is_same_v<T,double>` -->检查T与double是否相同,返回bool
    > `if constexpr ()` --> 编译时条件判断,只有满足条件的代码块才会被编译
