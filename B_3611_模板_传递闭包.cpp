#include <bits/stdc++.h>
#if 0
    #define int long long
#endif
using ll=long long;

const int N=1e3+10;
int n,m;
int dp[N][N];
signed main(){
    std::cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            std::cin>>dp[i][j];
        }
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dp[i][j]=std::max(dp[i][j],std::min(dp[i][k],dp[k][j]));
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            std::cout<<dp[i][j]<<' ';
        }
        std::cout<<'\n';
    }
    return 0;
}