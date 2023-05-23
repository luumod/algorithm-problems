#include <bits/stdc++.h>

int main(){
    std::string s1,s2;
    std::cin>>s1>>s2;
    int n1=s1.size(),n2=s2.size();
    std::vector<std::vector<int>> dp(n1,std::vector<int>(n2));
    for (int i=1;i<n1;i++){
        for (int j=1;j<n2;j++){
            if (i==1 || j==1){
                dp[i][j]=1;
                continue;
            }
            if (s1[i]==s2[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    std::cout<<dp[n1-1][n2-1];
	return 0;
}