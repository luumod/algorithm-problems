#include <bits/stdc++.h>

const int N=200010;
int n;
std::vector<bool> vis(N);
struct Node{
    int to,next,w;
}edge[N]; //这个地方
int head[N],cnt,ans=0;
std::unordered_set<std::pair<int,int>> ust;
void add_edge(int u,int v,int w){
    edge[++cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
int dfs(int now){
    vis[now]=true;
    int d1=0,d2=0;
    for (int j=head[now];j;j=edge[j].next){
        int to=edge[j].to;
        if (!vis[to]){
            int len=dfs(to)+edge[j].w;
            if (len>=d1){
                d2=d1,d1=len;
            }
            else if (len>d2){
                d2=len;
            }
        }   
    }
    ans=std::max(ans,d1+d2); //记录最大直径
    return d1;//返回最大长度
}
int main(){
    std::cin>>n;
    for (int i=1;i<n;i++){
        int x,y,w;
        std::cin>>x>>y>>w;
        add_edge(x,y,w);
        add_edge(y,x,w);
    }
    dfs(1);
    std::cout<<ans;
	return 0;
}