#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200005;
int t, n, n2, ans;
int a[N << 1];
int st[2][2][N], head[2][2], tail[2][2];
void process(int i, int l, int r)
{
    int num;
    while (l <= r)
    {
        num = 1;
        while (a[l] == a[l + 1] && l < r) num++, l++;
        if (num & 1)
        {
            ans++;
            if (num == 1) st[i][0][++tail[i][0]] = a[l];
        }
        else
            st[i][1][++tail[i][1]] = a[l];

        // cout << l << ' ' << num << endl;
        l++;
    }
    // cout << tail[i][0] << ' ' << tail[i][1] << endl << endl;
}
void solve()
{
    scanf("%d", &n);
    n2 = (n << 1), ans = 0;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) head[i][j] = 1, tail[i][j] = 0;
    for (int i = 1; i <= n2; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n2 + 1);
    process(0, 1, n), process(1, n + 1, n2);
    while (head[0][1] <= tail[0][1] && head[1][1] <= tail[1][1])
    {
        if (st[0][1][head[0][1]] == st[1][1][head[1][1]]) break;
        ans += 4;
        head[0][1]++, head[1][1]++;
    }
    while (head[0][1] <= tail[0][1] && head[1][0] <= tail[1][0])
    {
        if (st[0][1][head[0][1]] == st[1][0][head[1][0]]) break;
        ans += 2;
        head[0][1]++, head[1][0]++;
    }
    while (head[1][1] <= tail[1][1] && head[0][0] <= tail[0][0])
    {
        if (st[1][1][head[1][1]] == st[0][0][head[0][0]]) break;
        ans += 2;
        head[1][1]++, head[0][0]++;
    }
    cout << ans << endl;
}

int main()
{
    // freopen("test.in", "r", stdin);
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
