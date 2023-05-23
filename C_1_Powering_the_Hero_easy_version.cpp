#include <bits/stdc++.h>
#define int long long
void solve() {
    /*
   0: 取出栈顶牌
   positive: 如果当前牌比栈顶的牌小，则舍弃，否则替换
   */
    int n;
    std::cin >> n;
    std::priority_queue<int,std::vector<int>> q;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int num;
        std::cin >> num;
        if (num) {
            q.push(num);
        }
        else if (num == 0 && !q.empty()) {
            ans += q.top();
            q.pop();
        }
    }
    std::cout << ans << '\n';
}
signed main() {
    int n;
    std::cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}