#include <bits/stdc++.h>

const int mod=1e9+7;
using ll=long long;
void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n),b(n);
    for (auto& x:a){
        std::cin>>x;
    }
    for (auto& x:b){
        std::cin>>x;    
    }
    ll ans=1;
    std::sort(a.begin(),a.end());
    std::sort(b.begin(),b.end(),std::greater<int>());
    for (int i=0;i<b.size();i++){
        int x=b[i];
        auto sz=a.end()-std::upper_bound(a.begin(),a.end(),x);
        ans=ans*(sz-i)%mod;
        if (sz-i<=0){
            std::cout<<0<<'\n';
            return;
        }
    }
    std::cout<<ans<<'\n';
}
signed main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
    return 0;
}