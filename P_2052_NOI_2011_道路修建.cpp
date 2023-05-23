#include <bits/stdc++.h>
#if 1
    #define int long long
#endif
using ll=long long;

const int N=1e6+10;
int n,m;
struct Node{
    int to,next,w;
}edge[N<<2];
int head[N],cnt;
int cntl[N],cntr[N],ans;
void add_edge(int u,int v,int w){
    edge[++cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
std::pair<int,int> dfs(int now,int father){
    //以now为根的左右子树的节点个数
    int cur=1; //当前子树节点数量
    int left=0;//其余节点的数量
    int p=0;
    for (int i=head[now];i;i=edge[i].next){
        int x=edge[i].to;
        if (x!=father){
            auto p=dfs(x,now);
            ans+=p.second*edge[i].w; 
            cur+=p.first; //子树的节点数
        }
    }
    left=n-cur; //剩余的节点数量
    p=abs(cur-left);
    return {cur,p};
}
signed main(){
    std::cin>>n;
    for (int i=1;i<n;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    dfs(1,0);
    std::cout<<ans;
    return 0;
}