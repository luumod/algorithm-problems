#include <bits/stdc++.h>

int main(){
    int n,W;
    std::cin>>n>>W;
    std::vector<int> ws(n+1),ts(n+1);
    std::vector<double> dp(W+1);
    for (int i=1;i<=n;i++){
        std::cin>>ws[i]>>ts[i];
    }
    auto check=[&](double x){
        //ws[i]为第i个物品的重量
        //ts[i]-x*ws[i]为第i个物品的价值
        for (int i=1;i<=W;i++){
            dp[i]=-1e9;
        }
        
        for (int i=1;i<=n;i++){
            for (int j=W;j>=0;j--){
                //重量大于W的也按照W来算
                int k=std::min(W,j+ws[i]);
                dp[k]=std::max(dp[k],dp[j]+ts[i]-x*ws[i]);
            }
        }
        return dp[W]>=0; //分数规划：求最大值
    };  
    //我们需要求最大的比值 tsum/wsum
    double l=0,r=1000;
    while (r-l>1e-5){
        double mid=(l+r)/2;
        if (check(mid)){
            l=mid;  //求最大值
        }
        else{
            r=mid;
        }
    }
    std::cout<<int(r*1000);
	return 0;
}