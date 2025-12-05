#include<iostream>
#include<regex>
#include<string>
using namespace std;

const double Limit=10000.0;
template<typename T>
class Calculator
{
private:
    static const regex formula; // 正则表达式对象,用于匹配输入的表达式
    void calculate(T a,T b,char op); // 计算函数
public:
    bool preprocess(string expression); // 预处理输入的表达式,包括语法检查和调用计算函数
    
};

template<>
const regex Calculator<double>::formula(R"(\s*([+-]?\d+(?:\.\d+)?)\s*([+\-*/])\s*([+-]?\d+(?:\.\d+)?)\s*)"); // 匹配形如"1+1"或"1 + 1"的表达式

template<>
const regex Calculator<int>::formula(R"(\s*([+-]?\d+)\s*([+\-*/])\s*([+-]?\d+)\s*)");

template<typename T>
bool Calculator<T>::preprocess(string expression)
{
    {
        smatch parts;
        if(!regex_match(expression,parts,formula)) // 如果表达式不符合正则表达式的规则
        {
            cout<<"Expression error!"<<endl;
            return 0;
        }

        T a,b;
        char op;

        if constexpr (is_same<T,double>::value)
        {
            a=stod(parts[1].str());
            b=stod(parts[3].str());
        }
        else
        {
            a=stoi(parts[1].str());
            b=stoi(parts[3].str());
        }
        op=parts[2].str()[0];
        
        if(a<-Limit || a>Limit || b<-Limit || b>Limit) // 如果数字超出范围
        {
            cout<<"Number out of range!"<<endl;
            return 0;
        }
        if(op=='/' && b==0) // 如果除数为零
        {
            cout<<"Division by zero!"<<endl;
            return 0;
        }

        calculate(a,b,op);
        return 1;
    }
}

template<typename T>
void Calculator<T>::calculate(T a,T b,char op)
{
    T result;
    switch(op)
    {
        case '+':
            result=a+b;
            break;
        case '-':
            result=a-b;
            break;
        case '*':
            result=a*b;
            break;
        default:
            result=a/b;
            break;
    }
    cout<< a << " " << op << " " << b << " = " << result << endl;
}

int main()
{
    cout<<"请用户输入单项数学式(输入'exit'退出)\n";
    Calculator<double> calcd;
    Calculator<int> calci;
    while(1)
    {
        string expression;
        getline(cin,expression);
        if(expression=="exit")
            break;
        if(regex_search(expression,regex(R"(\.)")))
        {
            if(!calcd.preprocess(expression))
                cout<<"\n请重新输入\n";
            else
                cout<<"\n请继续输入\n";
        }
        else
        {
            if(!calci.preprocess(expression))
                cout<<"\n请重新输入\n";
            else
                cout<<"\n请继续输入\n";
        }
    }
    return 0;
}