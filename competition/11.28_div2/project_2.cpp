#include <iostream>
#include <cstdio>
using namespace std;

int t;
int n, a[200010];
long long tot, maxx, num;
int solve()
{
    cin >> n;
    maxx = num = tot = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tot += a[i];
        if (a[i]) num++;
        if (a[i] > maxx) maxx = a[i];
    }
    if (tot - num >= n - 1) return num;
    return tot - n + 1;
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) printf("%d\n", solve());
    return 0;
}
