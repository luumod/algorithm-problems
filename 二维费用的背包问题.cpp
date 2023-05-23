#include <bits/stdc++.h>

const int N=110;
void TwoBag(){
    for (int i=1;i<=n;i++){
        for (int j=V;j>=Wei[i];j--){ //背包容量
            for (int z=M;z>=Zho[i];z--){ //背包重量
                dp[j][z]=std::max(dp[j][z],dp[j-Wei[i]][z-Zho[i]]+Val[i]);
            }
        }
    }
    std::cout<<dp[V][M];
}   
int main(){
    int n,V,M;
    int dp[N][N];
    std::cin>>n>>V>>M;
    std::vector<int> Wei(n+1),Zho(n+1),Val(n+1);
    for (int i=1;i<=n;i++){
        std::cin>>Wei[i]>>Zho[i]>>Val[i];
    }
    TwoBag();
	return 0;
}