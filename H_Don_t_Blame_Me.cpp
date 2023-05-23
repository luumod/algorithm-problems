#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int B = 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> dp(1 << B, 1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            dp[x] = 2 * dp[x] % MOD;
        }
        for (int i = 0; i < B; i++) {
            for (int j = 0; j < (1 << B); j++) {
                if ((j >> i) & 1) {
                    dp[j ^ (1 << i)] = 1LL * dp[j ^ (1 << i)] * dp[j] % MOD;
                }
            }
        }
        for (int i = 0; i < B; i++) {
            for (int j = 0; j < (1 << B); j++) {
                if ((j >> i) & 1) {
                    dp[j ^ (1 << i)] = (dp[j ^ (1 << i)] - dp[j]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < (1 << B); i++) {
            if (__builtin_popcount(i) == k) {
                ans = (ans + dp[i]) % MOD;
            }
        }
        if (k == B) ans--;
        if (ans < 0) ans += MOD;
        cout << ans << '\n';
    }
}
