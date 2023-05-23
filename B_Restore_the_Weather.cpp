#include <bits/stdc++.h>
#if 0
    #define int long long
#endif
using ll=long long;

const int N=1e5+10;
int n,m,k;
void solve(){
    std::cin>>n>>k;
    std::vector<int> a(n),b(n);
    for (auto& x:a){
        std::cin>>x;
    }
    for (auto& x:b){
        std::cin>>x;
    }
    std::vector<int> mp(n),ans(n);
    std::iota(mp.begin(),mp.end(),0);
    std::sort(mp.begin(),mp.end(),[&](int i,int j){
        return a[i]<a[j];
    });
    //mp表示将a按正序排列，将下标映射到mp：mp[i]: a[mp[i]]
    std::sort(b.begin(),b.end());
    for (int i=0;i<n;i++){
        ans[mp[i]]=b[i];
    }
    for (int i=0;i<n;i++){
        std::cout<<ans[i]<<" \n"[i==n-1];
    }
}
signed main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
    return 0;
}