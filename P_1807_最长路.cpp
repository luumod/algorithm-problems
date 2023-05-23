#include <bits/stdc++.h>

const int N=5e3+10;
std::vector<std::pair<int,int>> vec[N];
int val[N];
int dp[N]; //记录路径
int in[N];
int main(){
    int n,m;
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        vec[u].push_back({v,w});
        ++in[v]; //入度标记
    }
    std::queue<int> q;
    memset(dp,-0x3f,sizeof(dp));
    dp[1]=0;
    for (int i=1;i<=n;i++){
        if (!in[i]){
            q.push(i);
        }
    }
    while (!q.empty()){
        int u=q.front();
        q.pop();
        for (auto& p:vec[u]){
            int v=p.first,w=p.second; //x是p到达的点
            --in[v];
            if (in[v]==0){
                q.push(v); //入度=0 加入队列
            }
            dp[v]=std::max(dp[v],dp[u]+w);
        }
    }
    if (dp[n]<0){
        std::cout<<-1<<'\n';
        return 0;
    }
    std::cout<<dp[n];

	return 0;
}