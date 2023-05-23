#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> vec(n);
    for (auto& x:vec){
        std::cin>>x;
    }
    std::sort(vec.begin(),vec.end());
    /*
    1. 第一个数是奇数，则一定可以满足：
        1 2 4 6 8 --> 1 1 3 5 7
        1 3 5 7 9 --> 1 3 5 7 9
    2. 第一个数是偶数：如果存在奇数就不满足
        1. 后面都是奇数： 2 3 5 7 --> 2 3 2 2 不可以
        2. 后面都是偶数： 2 4 6 8 --> 2 4 6 8 一定可以
        3. 后面存在奇数和偶数： 2 4 5 6 --> 2 4 (5) 6 一定不可以
    */

    for (int i=1;i<n;i++){
        if (vec[0]%2==0 && vec[i]&1){
            std::cout<<"NO\n";
            return;
        }
    }
    std::cout<<"YES\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}