#include <bits/stdc++.h>

const int N=4e4+10;
int n,m;
int dp[100][N];  //dp[i][j]: 选择第i个物品后，背包还剩j容量的最大价值
int w[N],p[N];
std::vector<int> vec[100];
int sum[N];
void dfs(int now,int father){
    //预处理: 目前只选择当前物品，背包容量为i时的最大价值
    for (int i=w[now];i<=n;i++){
        dp[now][i]=w[now]*p[now];
    }
    for (auto& x:vec[now]){
        if (x!=father){
            dfs(x,now); 
            //分组背包
            for (int j=n;j>=w[now];j--){ //枚举背包容量，同时预留出当前物品的体积
                for (int k=0;k<=j-w[now];k++){ //枚举决策: 按单位体积拆分
                    dp[now][j]=std::max(dp[now][j],dp[now][j-k]+dp[x][k]);
                }
            }
        }
    }
}
int main(){
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b,fa;
        std::cin>>w[i]>>p[i]>>fa;
        vec[fa].push_back(i);
    }
    dfs(0,-1);
    int ans=0;
    // for (int i=0;i<=n;i++){
    //     ans=std::max(ans,dp[0][i]);
    // }   
    std::cout<<dp[0][n];
    return 0;
}