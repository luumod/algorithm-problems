#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> PII;
#define pb(s) push_back(s);
#define SZ(s) ((int)s.size());
#define ms(s,x) memset(s, x, sizeof(s))
#define all(s) s.begin(),s.end()
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N = 500010;

int n, k;
int pre[N], ne[N];
LL cnt[N];
void solve()
{
    cin >> n >> k;
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>> >q;
    for (int i = 1; i <= n; ++i) {
        LL v;
        cin >> v;
        q.push({v, i});
        pre[i] = i - 1;
        ne[i] = i + 1;
    }
    int g = n - k;
    while (q.size() > g) {
        auto p = q.top(); q.pop();
        LL v = p.first, ix = p.second;
        if (cnt[ix]) {
            q.push({v + cnt[ix], ix});
            cnt[ix] = 0;
        } else {
            int l = pre[ix], r = ne[ix];
            cnt[l] += v;
            cnt[r] += v;
            ne[l] = r;
            pre[r] = l;
        }
    }
    std::vector<LL> a(n + 1);
    for (int i = 0; i < g; ++i) {
        auto p = q.top(); q.pop();
        a[p.second] = p.first + cnt[p.second];
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i]) cout << a[i] << " ";
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}