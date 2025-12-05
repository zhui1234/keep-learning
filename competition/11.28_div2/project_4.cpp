#include <iostream>
#include <cstdio>
using namespace std;

int t, n, q;
string s;
int a, b, c;
int sum;
int num1, num2, num3, num4;
void solve()
{
    cin >> n >> q >> s;
    sum = 0;
    num1 = num2 = num3 = num4 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '?')
        {
            if (s[i + 1] == '?' && s[i - 1] != '?') num1++;
            if (s[i + 1] == 'V' || s[i + 1] == 'X') num2++;
            if (s[]) }
    }
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
