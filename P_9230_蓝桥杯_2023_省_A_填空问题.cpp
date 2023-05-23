#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[31][101],ans;
int main(){
	dp[0][0]=dp[1][0]=1;
	for(int i=1;i<=30;++i){
		for(int j=0;j<=100;j+=10){
            if (j==0){
                dp[i][j]=0;
                continue;
            }
			if(!dp[i][j])continue;
			if(j<=90)dp[i][j]+=dp[i-1][j-10];
			dp[i][0]+=dp[i-1][j];
		}
		ans+=dp[i][70];
	}
	printf("%lld\n",ans);
	//puts("8335366");
	return 0;
}