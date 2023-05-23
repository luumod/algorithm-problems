#include <bits/stdc++.h>

using ll=long long;
const int N=1e5+10,INF=2147483647;
struct Node{
    int to,w;
};
std::vector<Node> vec[N];
int vis[N];
ll dis[N]; 
int n,m,s;
std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> q;
void dijkstra(){
    for (int i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[s]=0;
    q.push({0,s});
    while (!q.empty()){
        auto p=q.top();
        q.pop();
        int u=p.second; //u表示当前点，first主要用于堆排序
        if (vis[u]){
            continue;
        }
        vis[u]=true;
        for (auto& x:vec[u]){
            int to=x.to,w=x.w;
            if (dis[to]>dis[u]+w){
                dis[to]=dis[u]+w;
                q.push({dis[to],to}); //入堆
            }
        }
    }
}
int main(){
    std::cin>>n>>m>>s;
    for (int i=1;i<=m;i++){
        int x,y,s;
        std::cin>>x>>y>>s;
        vec[x].push_back({y,s});
    }
    dijkstra();
    for (int i=1;i<=n;i++){
        std::cout<<dis[i]<<' ';
    }
	return 0;
}