#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> vec(n);
    std::iota(vec.begin(),vec.end(),1);
    for (auto& x:vec){
        std::cout<<x*2<<' ';
    }
    std::cout<<'\n';
}
int main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
    return 0;
}