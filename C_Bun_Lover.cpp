#include <bits/stdc++.h>
using ll=long long;
void solve(){
    ll n;
    std::cin>>n;
    ll ans=n*n-1+3+2*n;
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