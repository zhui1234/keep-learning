#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Image
{
private:
    vector< vector<int> >Imagedata;//图像数据
    int row,col;//row:行 col:列
public:
    Image(int r,int c): Imagedata(r,vector<int>(c,0)),row(r),col(c)
    {}//通过尺寸创建图像
    Image(vector<vector<int>> data):Imagedata(data),row(data.size()),col(data[0].size())
    {}//通过二位vector创建图像
    static const vector<vector<int>> Creeper;//设置静态常量成员
    void Print();//输出图像
};

const vector<vector<int>> Image::Creeper =
{
    {1,1,1,1,1},//1:黑色方块 0:白色方块
    {1,0,0,0,1},
    {1,1,0,1,1},
    {1,0,1,0,1},
    {1,1,1,1,1}
};

void Image::Print()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            cout<<(Imagedata[i][j]?"  ":"\u2588\u2588");
        cout<<'\n';
    }
}

int main()
{
    Image creeper=Image::Creeper;//初始化
    creeper.Print();
    return 0;
}
