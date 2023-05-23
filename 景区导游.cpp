#include <bits/stdc++.h>
#if 1
    #define int long long
#endif
using ll=long long;

const int N=1e5+10;
int n,m;
int dep[N],fa[N][30];
struct Node{
    int to,next,w;
}edge[N<<2];
int head[N],cnt,dis[N];
void add_edge(int u,int v,int w){
    edge[++cnt].w=w;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
void dfs(int now,int father){
    dep[now]=dep[father]+1;
    fa[now][0]=father;
    for (int i=1;i<=25;i++){
        fa[now][i]=fa[fa[now][i-1]][i-1];
    }
    for (int i=head[now];i;i=edge[i].next){
        int x=edge[i].to;
        if (x!=father){
            dis[x]=dis[now]+edge[i].w;
            dfs(x,now);
        }
    }
}
int lca(int x,int y){
    if (dep[x]<dep[y]){
        std::swap(x,y);
    }
    for (int i=25;i>=0;i--){
        if (dep[fa[x][i]]>=dep[y]){
            x=fa[x][i];
        }
    }
    if (x==y){
        return x;
    }
    for (int i=25;i>=0;i--){
        if (fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}
int get_dis(int x,int y){
    return dis[x]+dis[y]-2*dis[lca(x,y)];
}
signed main(){
    std::cin>>n>>m;
    for (int i=1;i<n;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    dfs(1,0);
    int query[N];
    for (int i=1;i<=m;i++){
        std::cin>>query[i];
    }   
    int sum=0;
    for (int i=1;i<m;i++){
        int a=query[i],b=query[i+1];
        sum+=get_dis(a,b); //总距离   
    }
    for (int i=1;i<=m;i++){
        int res=sum;
        if (i==1){
            res-=get_dis(query[i],query[i+1]);
        }
        else if (i==m){
            res-=get_dis(query[i-1],query[i]);
        }
        else{
            res+=get_dis(query[i-1],query[i+1])-get_dis(query[i-1],query[i])-get_dis(query[i],query[i+1]);
        }
        std::cout<<res<<' ';
    }
    return 0;
}