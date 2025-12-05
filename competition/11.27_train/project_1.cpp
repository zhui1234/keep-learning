#include <iostream>
#include <cstdio>
using namespace std;
using ll = long long;

int t;
ll n, k;
ll gcd(ll x)
{
    if ((x & 1) == 0) return 2;
    return 1;
}
void solve()
{
    cin >> n >> k;
    if (n % gcd(k) == 0)
        puts("YES");
    else
        puts("NO");
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
