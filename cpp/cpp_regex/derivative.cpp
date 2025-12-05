#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<regex>
#include<cmath>
using namespace std;

string s;
int len;
double x,ans;
bool flag;//标记是否为第一个项,第一个项不用输出+

int main()
{
    freopen("test.in","r",stdin);
    getline(cin,s);
    len=s.size();
    cin>>x;
    cout<<"f'(x)=";

    regex func_regex(R"(f\s*\(\s*x\s*\)\s*=\s*(.+))");//匹配函数表达式f(x)=...
    smatch func_match;
    
    string poly_part;//记录多项式部分
    regex_search(s, func_match, func_regex);
    poly_part = func_match[1].str();

    regex pattern1(R"(\s*\+?\s*(\d+)\s*(x)?\s*(?:\^\s*(\d+))?\s*(.*))");
    regex pattern2(R"(\s*\+?\s*(\d+)?\s*(x)\s*(?:\^\s*(\d+))?\s*(.*))");//匹配多项式的单项式部分
    int xs,zs;//系数和指数
    do
    {
        smatch sm;
        regex_match(poly_part, sm, pattern1);
        if(sm[0].str() == "")
            regex_match(poly_part, sm, pattern2);//分别用两种模式匹配单项式,避免bug
        //sm[0]:整体  sm[1]:系数  sm[2]:x  sm[3]:指数  sm[4]:剩余多项式
        if(sm[1] != "")
            xs=stoi(sm[1].str());
        else
            xs=1;
        if(sm[3] != "")
            zs=stoi(sm[3].str());
        else if(sm[2] != "")
            zs=1;
        else
            zs=0;
        xs*=zs;
        zs--;
        ans+=xs*pow(x,zs);
        if(xs)
        {
            if(poly_part != func_match[1].str() && flag)
                cout<<"+";
            if(xs==1)
                cout<<"x";
            else
                cout<<xs<<"x";
            if(zs)
                cout<<"^"<<zs;
            flag=1;
        }
        poly_part = sm[4].str();
    } while (poly_part != "");
    cout<<endl<<ans<<endl;
    return 0;
}
