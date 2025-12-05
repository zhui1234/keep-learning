# 1.编码

> [锟斤拷�⊠是怎样炼成的——中文显示“⼊”门指南【柴知道】](https://www.bilibili.com/video/BV1cB4y177QR/?share_source=copy_web&vd_source=9eebc0e143eff42351285a99b6d32e9a)
> ~~找到一个多年前看过的视频，讲得很清晰~~

## 1.1.理解编码

编码是一种对应关系,将字符与二进制数一一对应

## 1.2.常见编码

1.ASCII
2.GB2312(936) / GBK(936) / GB18030(54936)
3.UTF8(65001) / UTF16 / UTF32
> 括号内为编码对应的代码页编号

## 1.3.乱码原因

编码与解码方案不匹配

1. 源文件编码与编译器假设不匹配
2. 输出编码与终端编码不匹配

## 1.4.解决措施

核心：设置UTF-8编码

1. 使用system()函数

    ```C++
        system("chcp 65001 >nul");//"chcp 65001":将控制台代码页设置为65001 
                              //">nul":将命令的输出重定向到空设备，即隐藏命令执行结果
    ```

    > `system()`包含于`cstdlib`头文件中

2. 使用SetConsoleOutputCP()

    ```C++
        SetConsoleOutputCP(65001); //设置控制台输出编码为65001
                                   //类似的SetConsoleCP:设置控制台输入编码
    ```

    > `SetConsoleOutputCP`包含于`windows.h`头文件中
    > 可以在`#include<windows.h>`以及`SetConsoleOutputCP(65001);`前后分别加上`#ifdef WIN_32`及`#endif`确保在其他平台的兼容性
    > 可以在中文字符串前加上`u8`前缀确保字符串以UTF-8编码存储

3. way3 使用宽字符

    ```C++
    #include <iostream>
    #include <locale>
    #include <io.h>//提供底层io操作(输入 输出 打开/关闭文件等)和文件描述符操作(修改文件模式)
    #include <fcntl.h>//定义了常用文件打开方式(只读 只写等)和Unicode相关模式(UTF-8 UTF16等)

    int main()
    {
        _setmode(_fileno(stdout), _O_U8TEXT);//用U8还是U16取决于文件编码,不能用_O_WTEXT,会与C++标准流冲突
        /*经测试,环境配置好时不需要以下代码
        std::locale::global(std::locale(""));//设置全局C++本地化环境
        std::wcout.imbue(std::locale());//设置宽字符输出流的locale
        std::wcin.imbue(std::locale());设置宽字符输入流的locale
        */
        std::wcout << L"中文" << '\n';
        return 0;
    }
    ```

    > 宽字符使用std中的`wchar_t`(存储多字节字符),`wstring`,`wcin`,`wcout`
    > 宽字符/字符串前要加个`L`
