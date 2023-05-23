#include <bits/stdc++.h>

const int N=2e5+10;
int n;
int dp[N];
int main(){
    std::cin>>n;
    std::vector<int> vec(n+1);
    for (int i=1;i<=n;i++){
        std::cin>>vec[i];
    } 
    dp[1]=vec[1];
    long long ans=dp[1];
    for (int i=2;i<=n;i++){
        if (dp[i-1]<0){
            dp[i]=vec[i];
        }
        else{
            dp[i]=dp[i-1]+vec[i];
        }
        ans=std::max(ans,1ll*dp[i]);
    }
    std::cout<<ans;
    return 0;   
}