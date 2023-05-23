#include <bits/stdc++.h>
#if 0
    #define int long long
#endif
using ll=long long;

const int N=1e3+10;
int n,m;
int T[N],D[N],L[N];
int nums,fg,vis[N];
bool dfs(int now,int last){
    if (nums==n){
        return true;
    }
    for (int i=1;i<=n;i++){
        if (!vis[i] && T[i]+D[i]>=last){
            vis[i]=true;
            nums++;
            if (dfs(i,std::max(T[i],last)+L[i])){
                return true;
            }
            nums--;
            vis[i]=false;
        }
    }
    return false;
}
void solve(){
    std::cin>>n;
    for (int i=1;i<=n;i++){
        //T[i]时刻到达,继续盘旋D[i],降落需要L[i]
        std::cin>>T[i]>>D[i]>>L[i];
    }
    memset(vis,0,sizeof(vis));
    nums=0;

    if (dfs(1,0)){
        std::cout<<"YES\n";
    }
    else{
        std::cout<<"NO\n";
    }
}
signed main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
    return 0;
}