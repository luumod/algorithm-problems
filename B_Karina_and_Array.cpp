#include <bits/stdc++.h>
typedef long long ll;
const int N = 2e5+10;
void solve(){
    int n;
    std::cin>>n;
    ll nums[N];
    for (int i=1;i<=n;i++){
        std::cin>>nums[i];
    }
    ll mx = -LLONG_MAX;
    std::sort(nums+1,nums+1+n);
    for (int i=1;i<n;i++){
        mx = std::max(mx,nums[i]*nums[i+1]);
    }
    std::cout<<mx<<'\n';
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}