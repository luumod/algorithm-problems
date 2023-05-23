#include <bits/stdc++.h>

int main(){
    int n,m;
    std::cin>>n>>m;
#if 0
    //std::vector<int> arr(m,0);
    int A=1e9,B=0;
    std::vector<int> nums(m+1,0);
    for (int i=1;i<=m;i++){
        std::cin>>nums[i];
    }
    std::vector<int> mi,mx;
    std::deque<int> deq;
    for (int i=1;i<=m;i++){
        if (!deq.empty() && deq.front()<i-n+1){
            deq.pop_front();
        }
        while (!deq.empty() && nums[i]<=nums[deq.back()]){
            deq.pop_back();
        }
        deq.push_back(i);
        if (i>n-1){
            mi.push_back(nums[deq.front()]);
        }
    }
    deq.clear();
    for (int i=1;i<=m;i++){
        if (!deq.empty() && deq.front()<i-n+1){
            deq.pop_front();
        }
        while (!deq.empty() && nums[i]>=nums[deq.back()]){
            deq.pop_back();
        }
        deq.push_back(i);
        if (i>n-1){
            mx.push_back(nums[deq.front()]);
        }
    }
    int ans=1e9;
    for (int i=0;i<mi.size();i++){
        ans=std::min(ans,mx[i]-mi[i]);
    }
    std::cout<<ans;
#else
    std::vector<int> nums;
    for (int i=1;i<=m;i++){
        int num;
        std::cin>>num;
        nums.push_back(num);
    }
    std::sort(nums.begin(),nums.end());
    int ans=1e9;
    for (int i=0;i<m-n+1;i++){
        ans=std::min(ans,nums[i+n-1]-nums[i]);
    }
    std::cout<<ans;
#endif
	return 0;
}