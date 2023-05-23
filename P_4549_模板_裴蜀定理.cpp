#include <bits/stdc++.h>

using ll=long long;
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
int main(){
    int n;
    std::cin>>n;
    std::vector<int> vec(n);
    for (auto& x:vec){
        std::cin>>x;
    }
    ll ans=0;
    for (auto& x:vec){
        ans=gcd(ans,abs(x));
    }
    std::cout<<ans;
	return 0;
}