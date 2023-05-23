#include <bits/stdc++.h>

#define int long long 
void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> arr(n+1,0),b(n+1,0),sum(n+1,0);
    for (int i=1;i<=n;i++){
        std::cin>>arr[i];
        b[i]=i<=n+1-i?arr[i]+i:arr[i]+n+1-i;
    }
    //每次传送的最小总花费
    std::sort(b.begin()+1,b.begin()+1+n);
    for (int i=1;i<=n;i++){
        sum[i]=sum[i-1]+b[i]; //sum存储每次传送的总花费的前缀和
    }
    int ans=0;
    //枚举一个起始点从0开始
    for (int i=1;i<=n;i++){
        if (arr[i]+i>m){
            continue;
        }
        //需要合法才能作为起始点
        int t= i<=n+1-i?arr[i]+i:arr[i]+n+1-i;
        int k=std::upper_bound(sum.begin()+1,sum.begin()+1+n,m-arr[i]-i)-sum.begin()-1;
        if (b[k]<t){
            ans=std::max(ans,k+1);
        }
        else{
            k=std::upper_bound(sum.begin()+1,sum.begin()+1+n,m-arr[i]-i+t)-sum.begin()-1;
            ans=std::max(ans,k);
        }
    }
    std::cout<<ans<<'\n';
}
signed main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
    return 0;
}   