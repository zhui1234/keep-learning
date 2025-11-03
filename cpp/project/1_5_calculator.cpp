#include <iostream>
#include <regex>
#include <string>
using namespace std;

class Calculator
{
    public:
        double a,b;
        char op;
        void Input();
        void Print();
};
void Calculator::Input()
{
    cin>>a>>op>>b;
}

void Calculator::Print()
{
    cout<<a<<" "<<op<<" "<<b<<" = ";
    switch(op)
    {
        case '+':
            cout<<a+b<<'\n';
            break;
        case '-':
            cout<<a-b<<'\n';
            break;
        case '*':
            cout<<a*b<<'\n';
            break;
        default:
            if (b!=0)
                cout<<a/b<<'\n';
            else
                cout<<"Error: Division by zero"<<'\n';
            break;
    }
}

int main()
{
    Calculator calc;
    calc.Input();
    calc.Print();
    return 0;
}