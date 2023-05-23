#include <bits/stdc++.h>

const int N=310;
std::vector<int> tree[N];
std::vector<int> V(N),W(N);
int dp[N][N];
int n,M;
void dfs(int now){
    for (int i=W[now];i<=M;i++){
        dp[now][i]=V[now];
    }
    for (auto& son:tree[now]){
        dfs(son);
        for (int i=M;i>=W[now];i--){
            for (int j=0;j<=i-W[now];j++){
                dp[now][i]=std::max(dp[now][i],dp[now][i-j]+dp[son][j]);
            }
        }
    }
}
int main(){
    std::cin>>n>>M;
    for (int i=1;i<=n;i++){
        int fa;
        std::cin>>fa>>V[i];
        W[i]=1;
        tree[fa].push_back(i);
    }  
    dfs(0);
    std::cout<<dp[0][M];
	return 0;
}