#include <bits/stdc++.h>

int n;
const int INF=0x3F3F3F3F;
int main(){
    std::cin>>n;
    std::vector<int> vec(n+1),sum(n+1);
    std::vector<std::vector<int>> dp(n+1,std::vector<int>(n+1,INF));
    for (int i=1;i<=n;i++){
        std::cin>>vec[i];
        sum[i]=sum[i-1]+vec[i];
        dp[i][i]=0;
    }
    for (int len=2;len<=n;len++){
        for (int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            for (int k=l;k<r;k++){
                dp[l][r]=std::min(dp[l][r],dp[l][k]+dp[k+1][r]+sum[r]-sum[l-1]);
            }
        }
    }
    std::cout<<dp[1][n];
	return 0;
}