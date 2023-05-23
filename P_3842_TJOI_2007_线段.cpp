#include <bits/stdc++.h>

const int N=2e4+10;
int n;
int dp[N][2];
std::pair<int,int> pvec[N];
int main(){
    std::cin>>n;
    for (int i=1;i<=n;i++){
        int l,r;
        std::cin>>pvec[i].first>>pvec[i].second;
    }   
    dp[1][0]=pvec[1].second-1+pvec[1].second-pvec[1].first,dp[1][1]=pvec[1].second-1;
    //第一行只能往右走
    for (int i=2;i<=n;i++){
        //到达当前行的左端点: 从上一行的右端点或者左端点过来
       dp[i][0]=std::min(dp[i-1][0]+abs(pvec[i-1].first-pvec[i].second)+1+pvec[i].second-pvec[i].first,dp[i-1][1]+abs(pvec[i-1].second-pvec[i].second)+1+pvec[i].second-pvec[i].first);
       dp[i][1]=std::min(dp[i-1][0]+abs(pvec[i-1].first-pvec[i].first)+1+pvec[i].second-pvec[i].first,dp[i-1][1]+abs(pvec[i-1].second-pvec[i].first)+1+pvec[i].second-pvec[i].first);
    }
    std::cout<<std::min(dp[n][0]+(n-pvec[n].first),dp[n][1]+(n-pvec[n].second));
    return 0;
}