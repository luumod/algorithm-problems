#include <bits/stdc++.h>

const int N=5e3+10;
struct Edge{
    int to,next;
}edge[N<<2];
int head[N],cnt=1;
int n,m;
int dfn[N],low[N],tot;
std::stack<int> stk;
int dcc[N],all; //dcc是当前点所在连通块的编号 all是所有的数量
bool bri[N];  //记录割边
int nums[N];  //强连通分量

void add_edge(int u,int v){
    edge[++cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
void tarjan(int now,int in_edge){
    dfn[now]=low[now]=++tot;
    stk.push(now);
    for (int i=head[now];i;i=edge[i].next){
        int v=edge[i].to;
        if (!dfn[v]){
            tarjan(v,i);
            low[now]=std::min(low[now],low[v]);
            if (low[v]>dfn[now]){
                //从now到v是一条割边
                bri[i]=bri[i^1]=true; //对这条割边做标记
            }
        }
        else if (i!=(in_edge^1)){ //不是反边
            low[now]=std::min(low[now],dfn[v]);
        }
    }
    //缩点
    if (low[now]==dfn[now]){
        int y=0;
        ++all;
        do{
            y=stk.top();
            stk.pop();
            dcc[y]=all;
        }while (y!=now);
    }
}
int main(){
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        add_edge(u,v);
        add_edge(v,u);
    }
    tarjan(1,0);

    std::cout<<cnt<<'\n';

    std::cout<<all<<'\n';
    for (int i=1;i<=cnt;i++){
        if (bri[i]){
            std::cout<<i<<' ';
        }
    }

    for (int i=1;i<=cnt;i++){ //遍历所有的边
        if (bri[i]){ //如果是割边
            nums[dcc[edge[i].to]]++ ;
        }
    }
    int ans=0;
    for (int i=1;i<=all;i++){
        if (nums[i]==1){ //如果连通块所含节点为1个，则说明是一个叶子节点的联通块
            ans++; 
        }
    }
    std::cout<<(ans+1)/2;
    return 0;
}