#include <bits/stdc++.h>

int main(){
    int n,W;
    std::cin>>n>>W;
    std::vector<int> w,v,dp(W+1);
    for (int i=1;i<=n;i++){
        int weight,value,number;
        std::cin>>weight>>value>>number;
        for (int j=1;j<=number;j<<=1){
            w.push_back(j*weight);
            v.push_back(j*value);
            number-=j;
        }
        if (number){
            w.push_back(number*weight);
            v.push_back(number*value);
        }   
    }
    for (int i=0;i<w.size();i++){
        for (int j=W;j>=w[i];j--){
            dp[j]=std::max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    std::cout<<dp[W];
	return 0;
}