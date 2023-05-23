#include <bits/stdc++.h>
#define int long long
signed main(){
    int n,L;
    std::cin>>n>>L;
    std::vector<int> vec(n+1);
    for (int i=1;i<=n;i++){
        std::cin>>vec[i];
    }
    std::sort(vec.begin()+1,vec.begin()+1+n);
    // for (auto &x:vec){
    //     std::cout<<x<<' ';
    // }
    double ans=0;
    ans=std::max(vec[1]-0,L-vec[n]);
    for (int i=1;i<n;i++){
        ans=std::max(ans,double(vec[i+1]-vec[i])/2);
    }   
    printf("%.10lf",ans);
	return 0;
}