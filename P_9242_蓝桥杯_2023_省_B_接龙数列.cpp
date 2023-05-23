#include <bits/stdc++.h>
#if 0
    #define int long long
#endif
using ll=long long;

const int N=1e5+10;
int n,m;
std::string vec[N];
int dp[N];
signed main(){
    std::cin>>n;
    for (int i=1;i<=n;i++){
        std::cin>>vec[i];
    }
    for (int i=1;i<=n;i++){
        int back=vec[i].back()-'0',now=vec[i].front()-'0';
        //以back字符结尾的字符串的长度 = max(当前长度,上一个字符结尾的接龙的长度+1)
        dp[back]=std::max(dp[back],dp[now]+1);
    }
    int ans=0;
    for (int i=0;i<10;i++){
        ans=std::max(ans,dp[i]);
    }
    std::cout<<n-ans;
    return 0;
}