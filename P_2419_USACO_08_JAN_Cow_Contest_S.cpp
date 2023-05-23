#include <bits/stdc++.h>
#if 0
    #define int long long
#endif
using ll=long long;

const int N=1e3+10;
int n,m;
std::vector<int> vec[N];
int dp[N][N];
signed main(){
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        dp[u][v]=1;
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dp[i][j]=std::max(dp[i][j],std::min(dp[i][k],dp[k][j]));
            }
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        int a=1;
        for (int j=1;j<=n;j++){
            if (i==j){
                continue;
            }
            a=a&& (dp[i][j] ||dp[j][i]);
        }
        ans+=a;
    }
    std::cout<<ans;
    return 0;
}