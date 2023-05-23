#include <bits/stdc++.h>

int main(){
    int N,V;
    std::cin>>N>>V;
    std::vector<int> w(N+1),v(N+1),num(N+1),dp(V+1);
    for (int i=1;i<=N;i++){
        std::cin>>w[i]>>v[i]>>num[i];
    }
    for (int i=1;i<=N;i++){
        for (int j=V;j>=w[i];j--){
            for (int k=0;k<=num[i] && k*w[i]<=j;k++){
                dp[j]=std::max(dp[j],dp[j-k*w[i]]+k*v[i]);
            }
        }
    }
    std::cout<<dp[V]; //修改了内容
	return 0;
}