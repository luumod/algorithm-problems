#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;
    if (n==1){
        std::cout<<1<<'\n';
    }
    else if (n&1){
        std::cout<<-1<<'\n';
    }
    else{
        std::vector<int> vec(n+1),sum(n+1);
        std::iota(vec.begin(),vec.end(),0);
        for (int i=1;i<=n-1;i+=2){
            std::swap(vec[i],vec[i+1]);
        }
        for (int i=1;i<=n;i++){
            std::cout<<vec[i]<<' ';
        }
        std::cout<<'\n';
    }
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}