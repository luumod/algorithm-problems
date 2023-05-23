#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    std::vector<std::string> arr(n+1,"");
    std::vector<int> dp(10,0);
    for (int i=1;i<=n;i++){
        std::cin>>arr[i];
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        char now=arr[i].front();
        char back=arr[i].back();
        dp[back-'0']=std::max(dp[back-'0'],dp[now-'0']+1);
        /*
        dp[1]=1
        dp[1]=2
        dp[2]=max(0,1)=1
        dp[2]=max(1,3)=3
        dp[3]=max(0,4)=4
        */
    }
    for (int i=0;i<10;i++){
        ans=std::max(ans,dp[i]);
    }
    std::cout<<n-ans;
	return 0;
}