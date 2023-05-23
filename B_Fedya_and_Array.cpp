#include <bits/stdc++.h>
#if 1
    #define int long long
#endif
using ll=long long;

const int N=1e3+10;
int n,m,k;
int map[N][N];
void solve(){
    std::cin>>n>>m;
    std::cout<<(n-m)*2<<'\n';
    for (int i=0;i<n-m;i++){
        std::cout<<n-i<<' ';
    }
    for (int i=0;i<n-m;i++){
        std::cout<<m+i<<" \n"[i==n-m-1];
    }
}
signed main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
    return 0;
}