#include <bits/stdc++.h>
#include <ratio>
#define int long long

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
void solve(){
    int n;
    std::cin>>n;
    std::vector<int> vec(n);
    for (auto& x:vec){
        std::cin>>x;
    }
    int ans=0;
    for (int i=0;i<n;i++){
        ans=gcd(ans,abs(vec[i]-vec[n-i-1]));
    }
    std::cout<<ans<<'\n';
}
signed main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}