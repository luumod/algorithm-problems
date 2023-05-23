#include <bits/stdc++.h>
#define int long long
void solve(){
    int n,x1,y1,x2,y2;
    std::cin>>n>>x1>>y1>>x2>>y2;
    auto f=[](int n,int x1,int y1)->int{
        return std::min(std::min(x1,y1),std::min(n+1-x1,n+1-y1));
    };
    std::cout<<abs(f(n,x1,y1)-f(n,x2,y2))<<'\n';
}
signed main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}