#include <bits/stdc++.h>

int main(){
    int len,n,m;
    std::cin>>len>>n>>m;
    std::vector<int> vec(n+2);
    for (int i=1;i<=n;i++){
        std::cin>>vec[i]; //每块与起点的距离
    }
    vec[n+1]=len; //终点石头
    auto check=[&](int mid){
        int last=0,cnt=0;
        for (int i=1;i<=n+1;i++){
            if (vec[i]-vec[last]<mid){
                //两块石头之间的距离小于最短跳跃长度mid，则需要移除这块i石头
                cnt++;
            }          
            else{
                last=i;
            }  
        }
        return cnt<=m;
    };
    int l=0,r=1e9;
    while (l+1<r){
        int mid=l+r>>1;
        if (check(mid)){
            l=mid; //获得最大值
        }
        else{
            r=mid;
        }
    }
    std::cout<<l;
	return 0;
}