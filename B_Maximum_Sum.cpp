#include <bits/stdc++.h>
#define int long long
const int N=2e5+10;
std::vector<int> vec(N),sum(N);
void solve(){
    int n,k;
    std::cin>>n>>k;
    int ans=0;
    for (int i=1;i<=n;i++){
        std::cin>>vec[i];
        ans+=vec[i];
    }
    std::sort(vec.begin()+1,vec.begin()+1+n);
    for (int i=1;i<=n;i++){
        sum[i]=sum[i-1]+vec[i];
    }
    int res=0;
    for (int b=0;b<=k;b++){ //删除的最大的
        int temp=ans;   
        int s=k-b; //最小的次数
        temp-=(sum[n]-sum[n-b]);
        temp-=(sum[s*2]-sum[0]);
        res=std::max(res,temp);
    }
    std::cout<<res<<'\n';
}
signed main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
    return 0;
}