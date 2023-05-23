#include <bits/stdc++.h>

const int N = 15;
int n;
bool vis[N];
struct Node{
    int t,d,l;
};
std::vector<Node> nums;
bool dfs(int now,int lastT){
    if (now==n){
        return true;
    }
    for (int i=0;i<n;i++){
        if (!vis[i] && nums[i].t+nums[i].d>=lastT){
            vis[i]=true;
            if (dfs(now+1,std::max(lastT,nums[i].t)+nums[i].l)){
                return true;
            }
            vis[i]=false;
        }
    }
    return false;
}
void solve(){
    memset(vis,false,sizeof(vis));
    nums.clear();
    std::cin>>n;
    for (int i=1;i<=n;i++){
        int t,d,l;
        std::cin>>t>>d>>l;
        nums.push_back(Node{t,d,l});
    }
    if (dfs(0,0)){
        std::cout<<"YES\n";
    }
    else{
        std::cout<<"NO\n";
    }
}
int main(){ 
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
    return 0;
}