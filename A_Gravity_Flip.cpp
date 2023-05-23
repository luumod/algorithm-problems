#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    std::vector<int> nums;
    for (int i=1;i<=n;i++){
        int num;
        std::cin>>num;
        nums.push_back(num);
    }
    std::sort(nums.begin(),nums.end());
    for (auto &x:nums){
        std::cout<<x<<' ';
    }
	return 0;
}