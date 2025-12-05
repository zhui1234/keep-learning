#include <iostream>
#include <cstdio>
using namespace std;

int t, n, y, r;
void solve()
{
    cin >> n >> y >> r;
    cout << min(n, (y >> 1) + r) << endl;
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
