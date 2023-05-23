#include <bits/stdc++.h>
#if 1
    #define int long long
#endif
using ll=long long;

const int N=1e4+10;
int n,m;
int A[N],B[N];
int ans1=1e9,ans2=0;
void get(){
    for (int i=1;i<=n;i++){
        //最小答案最大值
        ans2=std::max(ans2,(int)ceil(A[i]/(B[i]+1)+1));
        //最大答案最小值
        ans1=std::min(ans1,A[i]/B[i]);
    }   
}
signed main(){
    std::cin>>n;
    for (int i=1;i<=n;i++){
        std::cin>>A[i]>>B[i];
    }
    get();
    std::cout<<ans2<<' '<<ans1;
    return 0;
}