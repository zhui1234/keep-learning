#include<iostream>
#include<regex>
using namespace std;

class Complex
{
private:
    double re,im; // re:实部  im:虚部
    static const regex formula_complex; // 正则表达式用于匹配复数格式
public:
    Complex(string s):re(0),im(0)
    {
        smatch parts;
        if(regex_match(s,parts,formula_complex))
        {
            //cout<<parts[0]<<'\n'<<parts[1]<<'\n'<<parts[2]<<'\n';
            if(parts[1].str()!="") // stod("")会报错
                re=stod(parts[1].str());
            if(parts[2].str()=="")
                im=0;
            else
            {
                if(parts[2].str()=="+") // 处理虚部为正号的情况
                    im=1;
                else
                {
                    if(parts[2].str()=="-")
                        im=-1;
                    else
                        im=stod(parts[2].str());
                }
            }
        }
        //cout<<re<<' '<<im<<'\n';
    }
    void Calc_and_Print(Complex c1,Complex c2,char op);
};

const regex Complex::formula_complex(R"(\s*(\-?\d+(?:\.\d+)?)?\s*([+-]?(?:\d+(?:\.\d+)?)?)?i?\s*)");
// 实部虚部都有可能为0,注意加上?
void Complex::Calc_and_Print(Complex c1,Complex c2,char op)
{
    double Re=0,Im=0;
    switch(op)
    {
        case '+':
            Re=c1.re+c2.re;
            Im=c1.im+c2.im;
            break;
        case '-':
            Re=c1.re-c2.re;
            Im=c1.im-c2.im;
            break;
        case '*':
            Re=c1.re*c2.re-c1.im*c2.im;
            Im=c1.re*c2.im+c1.im*c2.re;
            break;
        default:
            if(c2.re==0 && c2.im==0)
            {
                cout<<"Error"<<'\n';
                return;
            }
            double x=c2.re*c2.re+c2.im*c2.im;
            Re=(c1.re*c2.re+c1.im*c2.im)/x;
            Im=-(c1.re*c2.im-c1.im*c2.re)/x;
    }
    cout<<Re;
    if(Im>0)
    {
        if(Im!=1)
            cout<<'+'<<Im<<"i\n";
        else
            cout<<"+i\n";
    }
    else
    {
        if(Im!=-1)
            cout<<Im<<"i\n";
        else
            cout<<"-i\n";
    }
}

int main()
{
    //freopen("test.in","r",stdin);
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    Complex c1(s1),c2(s2);
    Complex calc("");
    calc.Calc_and_Print(c1,c2,'+');
    calc.Calc_and_Print(c1,c2,'-');
    calc.Calc_and_Print(c1,c2,'*');
    calc.Calc_and_Print(c1,c2,'/');
    return 0;
}