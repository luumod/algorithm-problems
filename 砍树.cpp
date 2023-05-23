#include <bits/stdc++.h>
#if 1
    #define int long long
#endif
using ll=long long;

const int N=1e5+10;
int n,m;
int dep[N],fa[N][30];
struct Node{
    int to,next,num;
}edge[N<<2];
int head[N],cnt,dis[N];
int diff[N],sum[N],edgeNum[N];
void add_edge(int u,int v,int num){
    edge[++cnt].to=v;
    edge[cnt].num=num;
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
            dfs(x,now);
            edgeNum[x]=edge[i].num;
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
int get(int now,int father){
    sum[now]=diff[now];
    for (int i=head[now];i;i=edge[i].next){
        int x=edge[i].to;
        if (x!=father){
            int val=get(x,now);
            sum[now]+=val;
        }
    }
    return sum[now];
}
signed main(){
    std::cin>>n>>m;
    for (int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        add_edge(u,v,i);
        add_edge(v,u,i);
    }
    dfs(1,0);
    std::pair<int,int> query[N];
    for (int i=1;i<=m;i++){
        int x,y;
        std::cin>>x>>y;
        query[i]={x,y};
    }
    for (int i=1;i<=m;i++){
        int fi=query[i].first,se=query[i].second;
        int f=lca(fi,se);
        diff[fi]++,diff[se]++,diff[f]-=2;
    }
    get(1,0);
    int res=-1;
    for (int i=1;i<=n;i++){
        if (sum[i]==m && (edgeNum[i]>res)){
            res=edgeNum[i];
        }
    }
    std::cout<<res;
    return 0;
}