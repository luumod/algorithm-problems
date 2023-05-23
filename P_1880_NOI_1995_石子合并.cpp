#include <bits/stdc++.h>

int n;
const int INF=0x3f3f3f3f;
int main(){
	std::cin>>n;
	std::vector<int> vec(2*n+1),sum(2*n+1);
	std::vector<std::vector<int>> dp(2*n+1,std::vector<int>(2*n+1,INF));
	std::vector<std::vector<int>> dp2(2*n+1,std::vector<int>(2*n+1,-INF));
	for (int i=1;i<=n;i++){
		std::cin>>vec[i];
		vec[i+n]=vec[i];
	}
	for (int i=1;i<=2*n;i++){
		sum[i]=sum[i-1]+vec[i];
		dp[i][i]=0,dp2[i][i]=0;
	}
	for (int len=2;len<=n;len++){
		for (int i=1;i+len-1<=2*n;i++){
			int r=i+len-1;
			for (int k=i;k<r;k++){
				dp[i][r]=std::min(dp[i][r],dp[i][k]+dp[k+1][r]+sum[r]-sum[i-1]);
				dp2[i][r]=std::max(dp2[i][r],dp2[i][k]+dp2[k+1][r]+sum[r]-sum[i-1]);
			}
		}
	}
	int mi=INF,mx=-INF;
	for (int i=1;i<=n;i++){
		mi=std::min(mi,dp[i][i+n-1]);
		mx=std::max(mx,dp2[i][i+n-1]);
	}

	std::cout<<mi<<'\n'<<mx;
	return 0;
}