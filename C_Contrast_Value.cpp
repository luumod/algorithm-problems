#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> vec(n);
    for (auto& x:vec){
        std::cin>>x;
    }
    n=std::unique(vec.begin(),vec.end())-vec.begin();
    int ans=0;
    for (int i=0;i<n;i++){
        if (i==0 || i==n-1 || vec[i]>vec[i-1] == vec[i]>vec[i+1]){
            ans++;
        }
    }
    std::cout<<ans<<'\n';
}
int main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }

    return 0;
}