#include <bits/stdc++.h>

const int N=2e5+10,INF=1e9;
struct Node{
    int to,w,next;
}edge[N<<2];
int head[N],cnt;
int d[N],f[N];
int fg[N];
void add_edge(int u,int v,int w){
    edge[++cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
int n;
int dfs_down(int now,int father){
    for (int j=head[now];j;j=edge[j].next){
        int to=edge[j].to;
        if (to!=father){
            //父节点根据子节点的下行流量和当前河道取一个最小值
            d[now]+=std::min(edge[j].w,dfs_down(to,now));
        }
    }
    if (fg[now]==1){
        return INF; //特判叶子节点的返回
    }
    else{
        return d[now];//当前下行流量返回到父节点
    }
}
int dfs_up(int now,int father){
    for (int j=head[now];j;j=edge[j].next){
        int to=edge[j].to;
        if (to!=father){
            //求某点的全流量
            if (fg[now]==1){
                f[to]=edge[j].w+d[to];
            }
            else{
                f[to]=d[to]+std::min(edge[j].w,f[now]-std::min(edge[j].w,d[to]));
            }
            dfs_up(to,now);
        }
    }
    return 0;
}
void solve(){
    cnt=0;
    memset(edge,0,sizeof(edge));
    memset(head,0,sizeof(head));
    memset(fg,0,sizeof(fg));
    memset(d,0,sizeof(d));
    memset(f,0,sizeof(f));
    std::cin>>n;
    for (int i=1;i<n;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        add_edge(u,v,w);
        add_edge(v,u,w);
        fg[u]++,fg[v]++; //如果某个节点只被标记了一次，则说明是叶子节点
    }
    //1. 下行dfs
    dfs_down(1,-1);
    f[1]=d[1];
    //2. 上行dfs
    dfs_up(1,-1);
    int ans=0;
    for (int i=1;i<=n;i++){
        ans=std::max(ans,f[i]);
    }
    std::cout<<ans<<'\n';
}
int main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
	return 0;
}