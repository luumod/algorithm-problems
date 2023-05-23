#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    std::vector<int> nums,dp(n);
    for (int i=1;i<=n;i++){
        int num;
        std::cin>>num;
        nums.push_back(num);
    }
    dp[0] = 1;
    int ans = 1;
    for (int i=0;i<n-1;i++){
        if (nums[i+1]>=nums[i]){
            dp[i+1] = dp[i]+1;
        }
        else{
            dp[i+1] = 1;
        }
    }
    std::cout<<*max_element(dp.begin(),dp.end());
	return 0;
}