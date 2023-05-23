#include <bits/stdc++.h>
#if 0
    #define int long long
#endif
using ll=long long;

const int N=1e3+10;
int n,m,k;
int map[N][N];
void solve(){
    std::cin>>n>>k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            std::cin>>map[i][j];
        }
    }
    int no=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (map[i][j]!=map[n-i+1][n-j+1]){
                no++;
                map[i][j]^=1;
            }
        }
    }
    //必须操作k次
    if (no<=k){
        if (n&1){
            //无限次的改变中间的元素
            std::cout<<"YES\n";
        }
        else{
            if ((k-no)%2==0){
                std::cout<<"YES\n";
            }
            else{
                std::cout<<"NO\n";
            }
        }
    }
    else{
        std::cout<<"NO\n";
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