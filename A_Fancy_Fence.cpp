#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;
    int wj=180-n;
    if (360%wj!=0){
        std::cout<<"NO\n";
    }
    else{
        std::cout<<"YES\n";
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