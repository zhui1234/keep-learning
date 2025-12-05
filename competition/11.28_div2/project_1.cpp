#include <iostream>
#include <cstdio>
using namespace std;

int t, n;
int solve()
{
    cin >> n;
    if (n == 1) return 1;
    if (n == 2) return 9;
    if (n == 3) return 29;
    if (n == 4) return 56;
    return 5 * (n * n - n - 1);
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) printf("%d\n", solve());
    return 0;
}
