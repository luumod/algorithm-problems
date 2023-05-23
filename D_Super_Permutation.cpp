#include <bits/stdc++.h>

int n;
void solve(){
    std::cin>>n;
    if (n==1){
        std::cout<<1<<'\n';
        return;
    }
    if (n&1){
        std::cout<<-1<<'\n';
        return;
    }
    std::cout<<n<<' '<<n-1<<' ';
    for (int i=2;i<=n-2;i+=2){
        std::cout<<i<<' '<<(n-1)-i<<' ';
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