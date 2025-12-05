#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;

int t, n, num, top;
ll k;
ll q[200010], r[200010];
bool find(int x, int L, int R)
{
    // cout << q[x] << endl;
    while (L < R)
    {
        int mid = L + R >> 1;
        // cout << L << ' ' << R << ' ' << mid << ' ' << r[mid] << endl;
        if (q[x] + (q[x] + 1) * r[mid] <= k)
            R = mid;
        else
            L = mid + 1;
    }
    // cout << L << endl;
    if (q[x] + (q[x] + 1) * r[L] > k) return 0;
    top = L + 1;
    num++;
    return 1;
}
void solve()
{
    cin >> n >> k;
    top = 1;
    num = 0;
    for (int i = 1; i <= n; i++) cin >> q[i];
    for (int i = 1; i <= n; i++) cin >> r[i];
    sort(q + 1, q + n + 1, less<ll>());
    sort(r + 1, r + n + 1, greater<ll>());
    for (int i = 1; i <= n && top <= n; i++)
        if (!find(i, top, n)) break;
    printf("%d\n", num);
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
