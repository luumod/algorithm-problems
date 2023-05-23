#include <bits/stdc++.h>
#define int long long
signed main(){
    int n,k;
    std::cin>>n>>k;
    std::vector<int> vec(n+1),sum(n+1);
    for (int i=1;i<=n;i++){
        std::cin>>vec[i];
    }
    for (int i=1;i<=n;i++){
        sum[i]=sum[i-1]+vec[i];
    }
    int ans=1e9+10;
    int idx=0;
    for (int i=k;i<=n;i++){
        if (ans>sum[i]-sum[i-k]){
            idx=i-k+1;
            ans=sum[i]-sum[i-k];
        }
    }
    std::cout<<idx;
	return 0;
}