#include <iostream>
#include <cstdlib>
#include <cstring>

const int N=500;
double dp[N][N]; //第i轮第j个队获胜的概率
double p[N][N]; 
int n;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    while (std::cin>>n){
        if (n==-1){
            break;
        }
        int m=1<<n;
        for (int i=0;i<m;i++){
            for (int j=0;j<m;j++){
                std::cin>>p[i][j];
            }
        }
        memset(dp,0,sizeof(dp));
        for (int i=0;i<m;i++){
            dp[0][i]=1; //第0轮自身一定是获胜的
        }
        //1 2 --> 1
        //3 4 --> 3
        //1 3 --> 1 over
        for (int i=1;i<=n;i++){ //第i轮
            for (int j=0;j<m;j++){ //当前j队
                for (int k=0;k<m;k++){ //前一轮k队
                    if (((j>>(i-1))^1)==(k>>(i-1))){
                        //前一轮k获胜的概率*前一轮j获胜的概率*当前轮j对k获胜的概率
                        dp[i][j]+=dp[i-1][k]*dp[i-1][j]*p[j][k];
                    }
                }
            }
        }
        double mx=0;
        int ans=0;
        for (int i=0;i<m;i++){
            if (dp[n][i]>mx){
                mx=dp[n][i];
                ans=i;
            }
        }
        std::cout<<ans+1<<'\n';
    }
	return 0;
}