#include <bits/stdc++.h>

using ll=long long;
const int N=110,INF=1061109567;
int dp[N][N],val[N][N];
int n,m;
ll ans=INF;
void floyd(){
    for (int k=1;k<=n;k++){
        //经过前k-1个点的最短路更新
        //寻找第k个点的前两个点进行计算最小环的及其长度
        //第i和j点之间的最短路径一定是已经计算过的
        for (int i=1;i<k;i++){
            for (int j=i+1;j<k;j++){
                ans=std::min(ans,1ll*dp[i][j]+val[i][k]+val[j][k]);
            }
        }
        //经过第k个点的最短路更新
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dp[i][j]=std::min(dp[i][j],dp[i][k]+dp[k][j]);
            }

        }
    }
}
int main(){
    memset(dp,0x3f,sizeof(dp));
    memset(val,0x3f,sizeof(val));
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        int x,y,w;
        std::cin>>x>>y>>w;
        dp[x][y]=dp[y][x]=val[x][y]=val[y][x]=w;
    }
    for (int i=1;i<=n;i++){
        dp[i][i]=val[i][i]=0;
    }
    floyd();
    if (ans==INF){
        std::cout<<"No solution.\n";
    }
    else{
        std::cout<<ans;
    }
	return 0;
}