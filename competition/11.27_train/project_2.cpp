#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
using ll = long long;

int t;
ll a, b;
ll factor(ll x)
{
    ll rx = sqrt(x), m = 1;
    for (int i = rx; i >= 1; i--)
        if (x % i == 0)
        {
            m = i;
            break;
        }
    for (int i = rx + 1; i <= x; i++)
        if (x % i == 0)
        {
            if (x / i + i <= x / m + m) m = i;
            break;
        }
    return m;
}
void solve()
{
    cin >> a >> b;
    ll m1 = factor(a), m2 = factor(b);
    if (m1 > m2) swap(a, b), swap(m1, m2);
    for (int i = min(m2, a); i >= 1; i--)
        if (a % i == 0)
        {
            cout << a / i + b / m2 + m2 - 1 << endl;
            break;
        }
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
