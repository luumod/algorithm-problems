#include <bits/stdc++.h>

const int N=5e5+10,INF=1e9;
std::vector<int> vec[N];
std::pair<int,int> egPos[N];
int n,m;
int r1,r2,ok,vis[N],cnt;
std::vector<int> path(N,INF); 
bool dfs(int now){
    if (!ok){ //ok=true时则不会进入
        if (now>path[cnt]){
            //当前路径此时访问的点大于曾经的点，则直接退出
            return true;
        }
        if (now<path[cnt]){
            ok=true; //这条路径一定是目前来说最优的
        }
    }
    vis[now]=1;
    path[cnt++]=now; //记录此时的路径点
    for (auto& x:vec[now]){
        if (vis[x]){
            continue;
        }
        //不能访问断边对应的点
        if (x==r1 && now==r2){
            continue;
        }
        if (x==r2 && now==r1){
            continue;
        }
        if (dfs(x)){ //当不是最佳选择时直接返回true退出即可
            return true;
        }
    }
    return false; //否则在这条最佳选择道路上一直走
}
int main(){
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
        egPos[i]={u,v};  //记录这条边对应的两个点
    }
    for (int i=1;i<=n;i++){
        std::sort(vec[i].begin(),vec[i].end());
    }
    if (n-1==m){
        dfs(1);//点数比边数少1，就是一颗普通的树，则直接搜索
    }
    else{ //n==m
        //是一颗基环树，枚举每一条边当作断边
        for (int i=1;i<=m;i++){
            r1=egPos[i].first,r2=egPos[i].second;
            memset(vis,0,sizeof(vis));
            ok=false;
            cnt=0;
            dfs(1); //字典序最小开始，因此从1开始
        }
    }
    for (int i=0;i<n;i++){
        std::cout<<path[i]<<' ';
    }
    return 0;
}