#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> vec(n);
    for (auto &x:vec){
        std::cin>>x;
    }
    int ans=0;
    int len=0;
    for (int i=0;i<vec.size();i++){
        if (vec[i]==0){
            len++;
        }
        if (vec[i]!=0 || i==vec.size()-1){
            ans=std::max(ans,len);
            len=0;
        }
    }
    std::cout<<ans<<'\n';
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}