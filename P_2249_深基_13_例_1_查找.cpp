#include <bits/stdc++.h>


int main(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> vec(n+1);
    for (int i=1;i<=n;i++){
        std::cin>>vec[i];
    }
    auto binary_search1=[&](int x){
        int l=0,r=n+1;
        while (l+1<r){
            int mid=l+r>>1;
            //大于等于x的第一个数字
            if (vec[mid]>=x){
                r=mid;
            }
            else{
                l=mid;
            }
        }
        return vec[r]==x?r:-1;
    };
    auto binary_search2=[&](int x){
        int l=0,r=n+1;
        while (l+1<r){
            int mid=l+r>>1;
            //小于等于x的最后一个数字
            if (vec[mid]<=x){
                l=mid;
            }
            else{
                r=mid;
            }
        }
        return vec[r]==x?r:-1;
    };
    while (m--){
        int num;
        std::cin>>num;
        std::cout<<binary_search1(num)<<' ';
    }
	return 0;
}