#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    system("chcp 65001 >nul");// 设置控制台为UTF-8编码
    cout << "你好,世界!我是颠佬!" << '\n';
    return 0;
}
