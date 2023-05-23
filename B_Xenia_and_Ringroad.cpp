#include <bits/stdc++.h>

#define int long long
signed main(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> arr(m+1,0),next(m+1,0);
    for (int i=1;i<=m;i++){
        std::cin>>arr[i];
    }
    int cnt=0;
    for (int i=1;i<=m;i++){
        next[i]=arr[i];
        if (arr[i]<arr[i-1]){
            cnt++; //新的一圈
        }   
        next[i]+=cnt*n;
    }
    std::cout<<next[m]-1;
	return 0;
}