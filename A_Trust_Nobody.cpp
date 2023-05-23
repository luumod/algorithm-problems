#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> vec(n);
    int num=0;
    for (auto &x:vec){
        std::cin>>x;
    }
    std::sort(vec.begin(),vec.end());
    for (int i=0;i<=n;i++){
        int cnt=vec.end()-std::upper_bound(vec.begin(),vec.end(),i);
        if (cnt==i){
            std::cout<<cnt<<'\n';
            return;
        }
    }
    std::cout<<-1<<'\n';
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}