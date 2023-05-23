#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    std::vector<std::pair<int,int>> vec(n+1);
    int odd=0,even=0;
    int evenIdx=0,oddIdx=0;
    for (int i=1;i<=n;i++){
        int num;
        std::cin>>num;
        if (num&1){
            odd++;
            if (!oddIdx){
                oddIdx=i;
            }
        }
        else if ((num&1)==0){
            even++;
            if (!evenIdx){
                evenIdx=i;
            }
        }
    }
    int ans=0;
    if (odd>even){
        //找第一个偶数
        ans=evenIdx;
    }
    else{
        //找第一个奇数
        ans=oddIdx;
    }
    std::cout<<ans;
	return 0;
}