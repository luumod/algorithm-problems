#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
double X[20],Y[20];
//dp[i][j] 走到第i个奶酪并且状态为j的最短距离
double dp[20][34000]; 
double dis[20][20]; //两点之间最短距离
double getDis(int i,int j){
    return sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
}
int main(){
    int n=0;
    std::cin>>n;
    for (int i=1;i<=n;i++){
        std::cin>>X[i]>>Y[i];
    }
    X[0]=Y[0]=0.0;
    memset(dp,127,sizeof(dp)); //默认为最大值
    //预处理从i到j距离
    for (int i=0;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            dis[i][j]=dis[j][i]=getDis(i,j);
        }
    }
    //经过i点且状态为i的距离就等于dis[0][i]
    for (int i=1;i<=n;i++){
        dp[i][(1<<(i-1))]=dis[0][i];
    }
    for (int k=1;k<(1<<n);k++){ //枚举状态
        for (int i=1;i<=n;i++){ //枚举到达的所有点
            if ((k&(1<<(i-1)))==0){
                continue;
            }
            for (int j=1;j<=n;j++){ //枚举能在当前状态下到达当前点的位置j
                if (i==j){
                    continue;
                }
                if ((k&(1<<(j-1)))==0){ //j点没有走过
                    continue;
                }
                //到达i到j状态的最短距离 = min(到达j点且未经过i点的最短距离+i到j的点距离)
                dp[i][k] = std::min(dp[i][k],dp[j][k-(1<<(i-1))]+dis[i][j]);
            }
        }
    }
    double ans=INF;
    for (int i=1;i<=n;i++){
        ans=std::min(ans,dp[i][(1<<n)-1]);
    }
    printf("%.2f\n",ans);
	return 0;
}