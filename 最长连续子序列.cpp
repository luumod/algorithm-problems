#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    std::vector<int> vec(n+1);
    for (int i=1;i<=n;i++){
        std::cin>>vec[i];
    }
    std::unordered_map<char,int> ump;
    //寻找窗口中只包含两个元素的最长长度
    int ans=0;
    int left=1,right=1;
    while (right<=n){
        ump[vec[right]]++;
        if (ump.size()<=2){
            ans=std::max(ans,right-left+1);
        }
        while (ump.size()>2){
            ump[vec[left]]--;
            if (ump[vec[left]]==0){
                ump.erase(vec[left]);
            }
            left++;
        }
        right++;    
    }
    std::cout<<ans;
	return 0;
}