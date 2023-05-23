#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> vec(n),ans(n+1);
    for (int i=1;i<=n-1;i++){
        std::cin>>vec[i];
    }
    ans[1]=vec[1];
    for (int i=2;i<n;i++){
        ans[i]=std::min(vec[i],vec[i-1]);
    }
    ans[n]=vec.back();
    for (int i=1;i<=n;i++){
        std::cout<<ans[i]<<' ';
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