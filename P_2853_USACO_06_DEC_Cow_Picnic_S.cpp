#include <bits/stdc++.h>

const int N=1e3+10,M=1e4+10;
std::vector<int> edge[M];
int main(){
    int n,m,k;
    std::cin>>n>>m>>k;
    std::vector<int> ans(m+1),vis(m+1),arr(n+1);
    std::unordered_map<int,int> mp;
    for (int i=1;i<=n;i++){
        //奶牛的位置
        std::cin>>arr[i];
    }
    for (int i=1;i<=k;i++){
        //边
        int x,y;
        std::cin>>x>>y;
        edge[x].push_back(y); //有向边
    }
    std::function<void(int)> dfs=[&](int now){
        //每次遍历到一个牧场，表示当前牛可以到达此牧场
        vis[now]=true;
        ans[now]++;
        for (auto &x:edge[now]){
            if (!vis[x]){
                dfs(x); //遍历相邻的另一个点
            }
        }
    };  
    for (int i=1;i<=n;i++){
        dfs(arr[i]);
        std::fill(vis.begin(),vis.end(),0);
    }
    int res=0;
    for (int i=1;i<=m;i++){
        res+=(ans[i]==n);
    }
    std::cout<<res;
	return 0;
}