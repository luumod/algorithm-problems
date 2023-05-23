#include <bits/stdc++.h>

const int N=110;
int dp[N][N];
int n,m;
void floyd(){
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dp[i][j]=std::min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
}
int main(){ 
    memset(dp,0x3f3f3f3f,sizeof(dp));
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        int x,y,w;
        std::cin>>x>>y>>w;
        dp[x][y]=w;
        dp[y][x]=w;
    }
    for (int i=1;i<=n;i++){
        dp[i][i]=0;
    }
    floyd();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            std::cout<<dp[i][j]<<' ';
        }
        std::cout<<'\n';
    }
	return 0;
}