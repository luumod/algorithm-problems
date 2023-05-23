#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    std::vector<int> w(4),dp(n+1);
    std::cin>>w[1]>>w[2]>>w[3];
    std::fill(dp.begin(),dp.end(),-1);
    dp[0]=0;
    for (int i=1;i<=3;i++){
        for (int j=w[i];j<=n;j++){
            if (dp[j-w[i]]==-1) continue;
            dp[j]=std::max(dp[j],dp[j-w[i]]+1);
        }
    }
    std::cout<<dp[n];
	return 0;   
}   