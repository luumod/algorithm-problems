#include <bits/stdc++.h>
#if 1
    #define int long long
#endif
using ll=long long;

const int N=2e6+10;
int n,m,k,s,e;
struct Node{
    int to,next,w;
}edge[N<<2];
int head[N],cnt;
int dis[N],vis[N];
std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> q;
void add_edge(int u,int v,int w=0){
    edge[++cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
void dijkstra(int s){
    memset(dis,0x3f,sizeof(dis));
    q.push({0,s});
    dis[s]=0;   
    while (!q.empty()){
        auto p=q.top();
        q.pop();
        int u=p.second;
        if (vis[u]){
            continue;
        }
        vis[u]=true; //该点已松弛
        for (int i=head[u];i;i=edge[i].next){
            int x=edge[i].to;
            if (dis[x]>dis[u]+edge[i].w){
                dis[x]=dis[u]+edge[i].w;
                q.push({dis[x],x});
            }
        }
    }
}
signed main(){
    std::cin>>n>>m>>k;
    std::cin>>s>>e;
    for (int i=1;i<=m;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        add_edge(u,v,w);
        add_edge(v,u,w);
        //建立分层图
        for (int j=1;j<=k;j++){
            //两层之间连边:权值为0
            add_edge(u+(j-1)*n,v+j*n);
            add_edge(v+(j-1)*n,u+j*n);
            //下层的内部连边:权值为w
            add_edge(u+j*n,v+j*n,w);
            add_edge(v+j*n,u+j*n,w);
        }
    }
    for (int i=1;i<=k;i++){
        add_edge(e+(i-1)*n,e+i*n);
    }
    dijkstra(s);
    std::cout<<dis[e+n*k];
    return 0;
}