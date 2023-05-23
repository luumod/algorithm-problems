#include <bits/stdc++.h>
#define int long long
signed main(){
    int t;
    std::cin>>t;
    while (t--){
        int n;
        std::cin>>n;
        std::vector<int> nums(n+1,0),presum(n+1,0);
        for (int i=1;i<=n;i++){
            std::cin>>nums[i];
        }    
        std::sort(nums.begin(),nums.end());
        for (int i=1;i<=n;i++){
            presum[i]=nums[i];
            presum[i]+=presum[i-1];
        }
        presum[0] = 1;
        //如果一个数字之前的所有的数字之和比这个数字小，则一定无法生成
        bool fg=false;
        for (int i=1;i<=n;i++){
            if (presum[i-1]<nums[i]){
                fg=true;
                break;
            }
        }
        if (!fg){
            std::cout<<"YES\n";
        }
        else{
            std::cout<<"NO\n";
        }
    }
	return 0;
}