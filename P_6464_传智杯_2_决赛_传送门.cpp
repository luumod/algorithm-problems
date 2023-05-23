#include <bits/stdc++.h>
#if 0
    #define int long long
#endif
using ll=long long;

const int N=1e2+10;
int n,m;
int U[N],V[N],W[N];
int dp[N][N],t[N][N];
void floyd(){
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dp[i][j]=std::min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
}
signed main(){
    memset(dp,0x3f,sizeof(dp));
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        dp[u][v]=dp[v][u]=w;
        dp[u][u]=dp[v][v]=0;
    }
    floyd();
    long long ans=1e12;
    for (int a=1;a<n;a++){
        for (int b=a+1;b<=n;b++){
            //init
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++){
                    t[i][j]=dp[i][j];
                }
            }
            //枚举每条边加传送门    
            t[b][a]=t[a][b]=0;
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++){
                    t[i][j]=std::min(t[i][j],t[i][a]+t[a][j]);
                }
            }
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++){
                    t[i][j]=std::min(t[i][j],t[i][b]+t[b][j]);
                }
            }
            int res=0;
            for (int i=1;i<n;i++){
                for (int j=i+1;j<=n;j++){
                    res+=t[i][j];
                }
            }   
            ans=std::min(ans,1ll*res);
        }
    }
    std::cout<<ans;
    return 0;
}